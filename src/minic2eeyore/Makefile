all:	minic2eeyore

minic2eeyore:	lexer.l parser.y syntax_tree.c name_hash.c
	flex lexer.l
	bison -d -y parser.y --debug --verbose
	gcc -g -o minic2eeyore y.tab.c lex.yy.c syntax_tree.c name_hash.c -ly -ll

clean:
	rm -rf minic2eeyore *.o lex.yy.* *.tab.*