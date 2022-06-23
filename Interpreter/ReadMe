Interpreter for the test programming language. Implemented do...while, while, if, read, write statements. An example of using these operators will be below.
The language supports the following grammar

P → program D1; B@
D1 → var D {,D}
D → I {, I}: [ int [N] | bool[N]| bool| int ]
B → begin S {;S} end
S → I := E | I[E] := E | if E then S else S | while
E do S | B | read (I [E]) | read (I) | write (E)
E → E1 [ = | < | > | != ] E1 | E1
E1 → T {[ + | - | or ] T}
T → F {[ * | / | and ] F}
F → I | N | L | not F | (E) | I [E]
L → true | false
I → C | IC | IR
N → R | NR
C → a | b | ... | z | A | B | ... | Z
R → 0 | 1 | 2 | ... | 9

Example of the code. Sorting an array

program
var x : int[10],
z,c,tmp,f : int,
b : bool;

begin
z:=0;
while z<10 do
begin
	read(x[z]);
	z:=z+1
end;

z:=0;
while z<10 do
begin
	c:=0;
	b:=false;
	f:=0;
	while c<9-z do
		begin
		if x[c]>x[c+1] then
			begin
			tmp := x[c+1];
			x[c+1] := x[c];
			x[c] := tmp;
			b:=true
			end
		else f:=f+1;
		c:=c+1
		end;
	if not b then z:=10 else f:=f+1;
	z:=z+1
end;
z:=0;
while z<10 do
	begin
	write(x[z]);
	z:=z+1
	end
end
