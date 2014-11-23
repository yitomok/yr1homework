program task7;
procedure swap(var a:longint; var b:longint);
var tmp:longint;
begin
	tmp := a;
	a := b;
	b := tmp;
end;
var i, j, k, num:integer;
var p:array [1..100] of longint;
begin
	readln(num);
	for i := 1 to num do
		begin
			read(p[i]);

			if (i > 1) and (p[i] > p[i - 1]) then
				j := i - 1;
		end;

	if j = 0 then
		write('IMPOSSIBLE')
	else
		begin
			for i := j + 1 to num do
				if p[i] > p[j] then
					k := i;

			swap(p[j], p[k]);

			for i := j + 1 to (j + num) div 2 do
				swap(p[i], p[num - i + j + 1]);

			for i := 1 to num do
				write(p[i], ' ');
		end;
end.