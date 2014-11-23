program task3;
var i, p, input :integer;
begin
        read(input);
        for i := 1 to input do
        begin
                if ((i <> input) and (input mod i = 0)) then
                        p := p + i;
        end;
        if (p = input) then
                write('P');

        if (round(sqrt(input)) = sqrt(input)) then
                write('S');

        for i := 1 to round(sqrt(input)) do
                if (i * i * i = input) then
                        write('C');
end.