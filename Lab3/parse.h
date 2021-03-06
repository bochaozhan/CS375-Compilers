/* parse.h     Gordon S. Novak Jr.    */
/* 16 Apr 04; 23 Feb 05; 17 Nov 05; 18 Apr 06; 26 Jul 12; 07 Aug 13 */

/* You may use the function headers below if you wish, or you may
   replace them if you wish.  */

/*
 * Last modified: 0359, 14/07/30
 */

/* addint adds integer off to expression exp, possibly using tok */
TOKEN addint(TOKEN exp, TOKEN off, TOKEN tok);

/* addoffs adds offset, off, to an aref expression, exp */
TOKEN addoffs(TOKEN exp, TOKEN off);

/* appendst makes a progn containing statements followed by more */
TOKEN appendst(TOKEN statements, TOKEN more);

/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb);

/* binop links a binary operator op to two operands, lhs and rhs. */
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs);

TOKEN binop_type_coerce(TOKEN op, TOKEN lhs, TOKEN rhs);

/* cons links a new item onto the front of a list.  Equivalent to a push.
   (cons 'a '(b c))  =  (a b c)    */
TOKEN cons(TOKEN item, TOKEN list);

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok);

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok);

/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement);

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok);

/* fillintc smashes tok, making it into an INTEGER constant with value num */
TOKEN fillintc(TOKEN tok, int num);

/* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok);

/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok);

TOKEN get_last_link(TOKEN tok);

TOKEN get_last_operand(TOKEN tok);

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok);

/* instconst installs a constant in the symbol table */
void  instconst(TOKEN idtok, TOKEN consttok);

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok);

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist);

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok);

/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num);

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename);

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok);

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void  insttype(TOKEN typename, TOKEN typetok);

/* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void  instvars(TOKEN idlist, TOKEN typetok);

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok);

/* makefix forces the item tok to be integer, by truncating a constant
   or by inserting a FIXOP operator */
TOKEN makefix(TOKEN tok);

/* makefloat forces the item tok to be floating, by floating a constant
   or by inserting a FLOATOP operator */
TOKEN makefloat(TOKEN tok);

/* makefor makes structures for a for statement.
   sign is 1 for normal loop, -1 for downto.
   asg is an assignment statement, e.g. (:= i 1)
   endexpr is the end expression
   tok, tokb and tokc are (now) unused tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement);

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args);

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label);

/* makeif makes an IF operator and links it to its arguments.
   tok is a (now) unused token that is recycled to become an IFOP operator */
TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart);

/* makeintc makes a new token with num as its value */
TOKEN makeintc(int num);

/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel();

TOKEN makeloopincr(TOKEN var, int incr_amt);

/* makeop makes a new operator token with operator number opnum.
   Example:  makeop(FLOATOP)  */
TOKEN makeop(int opnum);

/* makeplus makes a + operator.
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makeplus(TOKEN lhs, TOKEN rhs, TOKEN tok);

/* makepnb is like makeprogn, except that if statements is already a progn,
   it just returns statements.  This is optional. */
TOKEN makepnb(TOKEN tok, TOKEN statements);

/* makeprogn makes a PROGN operator and links it to the list of statements.
   tok is a (now) unused token that is recycled. */
TOKEN makeprogn(TOKEN tok, TOKEN statements);

/* makeprogram makes the tree structures for the top-level program */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements);

TOKEN makerealtok(float num);
//TOKEN makerealtok(double num);

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr);

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high);
//TOKEN makesubrange(TOKEN tok, TOKEN low, TOKEN high);

TOKEN maketimes(TOKEN lhs, TOKEN rhs, TOKEN tok);

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement);

/* mulint multiplies expression exp by integer n */
TOKEN mulint(TOKEN exp, int n);

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
TOKEN nconc(TOKEN lista, TOKEN listb);

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field);

/* searchins will search for symbol, inserting it if not present. */
SYMBOL searchinsst(char name[]);

TOKEN search_rec(SYMBOL recsym, TOKEN field);

/* settoktype sets up the type fields of token tok.
   typ = type pointer, ent = symbol table entry of the variable  */
void  settoktype(TOKEN tok, SYMBOL typ, SYMBOL ent);

TOKEN std_fxn_args_type_check(TOKEN fn, TOKEN args);

/* talloc allocates a new TOKEN record. */
TOKEN talloc();

/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs);

/* wordaddress pads the offset n to be a multiple of wordsize.
   wordsize should be 4 for integer, 8 for real and pointers,
   16 for records and arrays */
int   wordaddress(int n, int wordsize);

TOKEN write_fxn_args_type_check(TOKEN fn, TOKEN args);

typedef short boolean;
#ifdef TRUE
#undef TRUE
#endif
#define TRUE 1

#ifdef true
#undef true
#endif
#define true 1

#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

#ifdef false
#undef false
#endif
#define false 0

/* Do not alter any macros below this line. */

#define DB_CONS       1             /* bit to trace cons() */
#define DB_BINOP      2             /* bit to trace binop() */
#define DB_MAKEIF     4             /* bit to trace makeif() */
#define DB_MAKEPROGN  8             /* bit to trace makeprogn() */
#define DB_PARSERES  16             /* bit to trace parseresult() */

#define DB_MAKEPROGRAM	32				/* bit to trace makeprogram() */
#define DB_MAKEFUNCALL	64				/* bit to trace makefuncall() */
#define DB_ADDINT		96				/* bit to trace addint() */
#define DB_FINDID		128				/* bit to trace findid() */
#define DB_FINDTYPE		256				/* bit to trace findtype() */
#define DB_ADDOFFS		384				/* bit to trace addoffs() */
#define DB_INSTVARS		512				/* bit to trace instvars() */
#define DB_INSTENUM		768				/* bit to trace instenum() */
#define DB_MAKEFOR		1024			/* bit to trace makefor() */
#define DB_INSTTYPE		1280			/* bit to trace insttype() */
#define DB_MULINT		2048			/* bit to trace mulint() */
#define DB_MAKEREPEAT	3072 //2560		/* bit to trace makerepeat() */
#define DB_UNARYOP		4096 //3072		/* bit to trace unaryop() */
#define DB_MAKEOP		5120 //3584		/* bit to trace makeop() */
#define DB_MAKEFLOAT	6144 //4096		/* bit to trace makefloat() */
#define DB_MAKEFIX		7168 //4608		/* bit to trace makefix() */
#define DB_MAKEGOTO		8192 //5120		/* bit to trace makegoto() */
#define DB_MAKELABEL	9216 //5632		/* bit to trace makelabel() */
#define DB_MAKEPNB		10240 //6144	/* bit to trace makepnb() */
#define DB_INSTCONST	11264 //6656	/* bit to trace instconst() */
#define DB_MAKEWHILE	12288 //7168	/* bit to trace makewhile() */
#define DB_COPYTOK		13312 //7680	/* bit to trace copytok() */
#define DB_INSTDOTDOT	14336 //8192	/* bit to trace instdotdot() */
#define DB_SEARCHINSST	15360 //8704	/* bit to trace searchinsst() */
#define DB_INSTPOINT	16384 //9216	/* bit to trace instpoint() */
#define DB_INSTREC		17408 //9728	/* bit to trace instrec() */
#define DB_INSTFIELDS	18432 //10240	/* bit to trace instfields() */
#define DB_MAKEPLUS		19456 //10752	/* bit to trace makeplus() */
#define DB_MAKEAREF		20480 //11264	/* bit to trace makearef() */
#define DB_REDUCEDOT	21504 //11776	/* bit to trace reducedot() */
#define DB_ARRAYREF		22528 //12288	/* bit to trace arrayref() */
#define DB_DOPOINT		23552 //12800	/* bit to trace dopoint() */
#define DB_INSTARRAY	24576 //13312	/* bit to trace instarray() */
#define DB_NCONC		25600 //13824	/* bit to trace nconc() */
#define DB_MAKEINTC		26624 //14336	/* bit to trace makeintc() */
#define DB_APPENDST		27648 //14848	/* bit to trace appendst() */
#define DB_DOGOTO		28672 //15360	/* bit to trace dogoto() */
#define DB_DOLABEL		29696 //15872	/* bit to trace dolabel() */
#define DB_INSTLABEL	30720 //16384	/* bit to trace instlabel() */
#define DB_SETTOKTYPE	31744 //16896	/* bit to trace settoktype() */
#define DB_MAKESUBRANGE	32768 //17408	/* bit to trace makesubrange() */

#define DEBUG (DB_MAKESUBRANGE * 2 - 1) & DEBUG_MASTER_SWITCH * (DB_MAKESUBRANGE * 2 - 1)		/* mask */

#define DB_PRINT_ARGS      0     /* print function arguments */

#define GEN_OUTPUT         1













/*

   addoffs adds offset, off, to an aref expression, exp
TOKEN addoffs(TOKEN exp, TOKEN off);

   arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled.
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb);

   dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled.
TOKEN dopoint(TOKEN var, TOKEN tok);

   instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok.
TOKEN instarray(TOKEN bounds, TOKEN typetok);

   instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled.
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok);

   instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns.
TOKEN instenum(TOKEN idlist);

   instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec()
TOKEN instfields(TOKEN idlist, TOKEN typetok);

   instpoint will install a pointer type in symbol table
TOKEN instpoint(TOKEN tok, TOKEN typename);

   instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype
TOKEN instrec(TOKEN rectok, TOKEN argstok);

   insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers.
void  insttype(TOKEN typename, TOKEN typetok);

   makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled.
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok);

   makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok.
TOKEN makesubrange(TOKEN tok, int low, int high);

   nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration.
TOKEN nconc(TOKEN lista, TOKEN listb);

   reducedot handles a record reference.
   dot is a (now) unused token that is recycled.
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field);
*/









