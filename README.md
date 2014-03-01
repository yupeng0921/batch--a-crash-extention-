batch--a-crash-extention-
=========================

Here is a summary of "batch"

"batch" is a crash extension. 

You can find crash here:

http://people.redhat.com/anderson/crash_whitepaper

"batch" is an interpreter. It give crash the ability to run script. It support a C like style script language. Generally you can call a crash command, and store the command output to a variable. Then get a part of the command output, transfer it to another crash command.For example, you know a super_block address is "ffff81087d829400", and you want to know the gendisk address corresponding to the super block.First, you should find the block_device address:

    crash> struct super_block.s_bdev ffff81087d829400
    
      s_bdev = 0xffff81087e1fbb80, 

Then, you find the gendisk from the block_device:

    crash> struct block_device.bd_disk 0xffff81087e1fbb80
    
      bd_disk = 0xffff81087f70e400,  

Use batch, you can write it as a script:

    cmd = "struct super_block.s_bdev " + "ffff81087d829400"; 
    callret = call(cmd);
    getret = get(callret, 0, 11, 18);
    cmd = "struct block_device.bd_disk " + getret;
    callret = call(cmd); getret = get(callret, 0, 0, -1);
    print getret;

"call" and "get" are buildin functions. "cmd", "callret", and "getret" are variables, and their type are string. Transfer a string to "call" function, it will exectute the string as a crash command, and return the crash command output as a string. In our example, we set the cmd varaible to a string:

    cmd = "struct super_block.s_bdev " + "ffff81087d829400";

It will set the "cmd" varaible to string:

    "struct super_block.s_bdev ffff81087d829400"

Then run the "call" function:

    callret = call(cmd);

It will run the crash command:

    struct super_block.s_bdev ffff81087d829400

And store the output to variable "callret". So after run that line, the value of "callret" will be:

    "  s_bdev = 0xffff81087e1fbb80, "

"get" function can get a substring of a string. It has 4 parameters, the first one is the input string, the second one specify which lines of the string, as the string may has many lines. The third parameter specify we get the substring from which characters on that line, and the fourth paramter specify how many characters we want to get.

So this line:

    getret = get(callret, 0, 11, 18);

means we get the first line (0 means first line, 1 means second line, and so on), from the 11th character, and get total 18 characters.

The "callret" varaible only has one line, that is line 0. Its 11th character is "0", from that character, we get 18 characters, the result will be:

    "0xffff81087e1fbb80"

It will be store to "getret" variable.

This line will print the string in variable getret:

    print getret;

The "print" function can print a string or number to screen.

To see the who document of batch, please download:
https://github.com/yupeng820921/batch--a-crash-extention-/raw/master/batch_manual.pdf
