normal:
	gcc -nostartfiles -shared -rdynamic -o batch.so batchcmd.c -fPIC -DX86_64 -D_FILE_OFFSET_BITS=64
whole:
	lex batch.l
	sed -in-place -e 's/yyin/batchyyin/g' lex.yy.c
	sed -in-place -e 's/yy_flush_buffer/batchyy_flush_buffer/g' lex.yy.c
	sed -in-place -e 's/yy_scan_buffer/batchyy_scan_buffer/g' lex.yy.c
	sed -in-place -e 's/yy_scan_bytes/batchyy_scan_bytes/g' lex.yy.c
	sed -in-place -e 's/yy_scan_string/batchyy_scan_string/g' lex.yy.c
	sed -in-place -e 's/yyout/batchyyout/g' lex.yy.c
	rm -f lex.yy.cn-place
	yacc batch.y
	gcc -nostartfiles -shared -rdynamic -o batch.so batchcmd.c -fPIC -DX86_64 -D_FILE_OFFSET_BITS=64
.PHONY: clean clean_whole
clean:
	rm -rf batch.so
clean_whole:
	rm -rf batch.so y_tab.c  lex.yy.c
