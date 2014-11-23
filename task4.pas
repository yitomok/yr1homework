program task4;
var i, n, max :integer;
var inputs :array [1..1000] of integer;
begin
	readln(n);
	for i := 1 to n do
	begin
		read(inputs[i]);
		if (inputs[i] >= max) then
			max := inputs[i];
        end;
	writeln(max);
	for i := 1 to n do
		if (inputs[i] = max) then
			write(i, ' ');
end.