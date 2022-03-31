/* -------------------------------------------------------
	Rules
	------------------------------------------------------- */

Rules 1 : 

	[Command Name]

	When the TOKEN is exactly a reserved word, the token identifier for that reserved word shall result. Otherwise, the token WORD shall be returned. Also, if the parser is in any state where only a reserved word could be the next correct token, proceed as above.
	Note:
		Because at this point quote marks are retained in the token, quoted strings cannot be recognized as reserved words. This rule also implies that reserved words are not recognized except in certain positions in the input, such as after a <newline> or semicolon; 
		the grammar presumes that if the reserved word is intended, it is properly delimited by the user, and does not attempt to reflect that requirement directly. Also note that line joining is done before tokenization, as described in Escape Character (Backslash) , 
		00so escaped <newline>s are already removed at this point.
	Rule 1 is not directly referenced in the grammar, but is referred to by other rules, or applies globally.

Rules 2 :

	[Redirection to or from filename]

	The expansions specified in Redirection shall occur. As specified there, exactly one field can result (or the result is unspecified), and there are additional requirements on pathname expansion.

Rules 3 :

	[Redirection from here-document]

	Quote removal shall be applied to the word to determine the delimiter that is used to find the end of the here-document that begins after the next <newline>.

Rules 4 :

	[Case statement termination]

	When the TOKEN is exactly the reserved word esac, the token identifier for esac shall result. Otherwise, the token WORD shall be returned.

Rules 5 :

	[NAME in for]

	When the TOKEN meets the requirements for a name (see the Base Definitions volume of IEEE Std 1003.1-2001, Section 3.230, Name), the token identifier NAME shall result. Otherwise, the token WORD shall be returned.

Rules 7 :

	[Assignment preceding command name]

		a. [When the first word]

		If the TOKEN does not contain the character '=', rule 1 is applied. Otherwise, 7b shall be applied.

		b. [Not the first word]

		If the TOKEN contains the equal sign character:

			If it begins with '=', the token WORD shall be returned.

			If all the characters preceding '=' form a valid name (see the Base Definitions volume of IEEE Std 1003.1-2001, Section 3.230, Name), the token ASSIGNMENT_WORD shall be returned. (Quoted characters cannot participate in forming a valid name.)

			Otherwise, it is unspecified whether it is ASSIGNMENT_WORD or WORD that is returned.

			Assignment to the NAME shall occur as specified in Simple Commands.


/* -------------------------------------------------------
	The grammar symbols
	------------------------------------------------------- */

%token  WORD
%token  ASSIGNMENT_WORD
%token  NAME
%token  NEWLINE
%token  IO_NUMBER


/*The following are the operators mentioned above.*/


%token	AND_IF	OR_IF
/*		'&&'	'||'	*/


%token	DLESS	DGREAT
/*		'<<'	'>>'	*/


/* -------------------------------------------------------
	The Grammar
	------------------------------------------------------- */


%start  complete_command
%%
					
complete_command	:	list separator
					|	list
					;
list				:	list separator_op and_or
					|					  and_or
					;
and_or				:							pipeline
					|	and_or AND_IF linebreak pipeline
					|	and_or OR_IF  linebreak pipeline
					;
pipeline			:	pipe_sequence
					;
pipe_sequence		:								command
					|	pipe_sequence '|' linebreak command
					;
command				:	simple_command
					|	compound_command
					|	compound_command redirect_list
					;
compound_command	:	subshell
					;
subshell			:	'(' compound_list ')'
					;
compound_list		:				 term
					|	newline_list term
					|				 term separator
					|	newline_list term separator
					;
term				:	term separator and_or
					|				   and_or
					;
name				:	NAME						 /* Apply rule 5 */
					;
wordlist			:	wordlist WORD
					|			 WORD
					;
pattern				:				WORD			/* Apply rule 4 */
					|	pattern '|' WORD			/* Do not apply rule 4 */
					;
					;
simple_command		:	cmd_prefix cmd_word cmd_suffix
					|	cmd_prefix cmd_word
					|	cmd_prefix
					|	cmd_name cmd_suffix
					|	cmd_name
					;
cmd_name			:	WORD					  /* Apply rule 7a */
					;
cmd_word			:	WORD					  /* Apply rule 7b */
					;
cmd_prefix			:				io_redirect
					|	cmd_prefix 	io_redirect
					|				ASSIGNMENT_WORD
					|	cmd_prefix 	ASSIGNMENT_WORD
					;
cmd_suffix			:				io_redirect
					|	cmd_suffix	io_redirect
					|				WORD
					|	cmd_suffix	WORD
					;
redirect_list		:					io_redirect
					|	redirect_list 	io_redirect
					;
io_redirect			:			  io_file
					|	IO_NUMBER io_file
					|			  io_here
					|	IO_NUMBER io_here
					;
io_file				:	'<'		 filename
					|	'>'		 filename
					|	DGREAT	 filename
					;
filename			:	WORD						  /* Apply rule 2 */
					;
io_here				:	DLESS	  here_end
					;
here_end			:	WORD						  /* Apply rule 3 */
					;
newline_list	 	:				 NEWLINE
					|	newline_list NEWLINE
					;
linebreak		 	:	newline_list
					|	/* empty */ 				/* <-je cois que c'est forcement ' ' */
					;
separator		 	:	newline_list
					;
sequential_sep		:	';' linebreak
					|	newline_list
					;