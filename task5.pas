program task5;
var i, n:integer;
var f,f1,a:longint;
begin
        readln(n);
        if n = 1 then
                a := 2
        else if n = 2 then
                a := 3
        else
        begin
                f := 2;
                f1 := 3;
                for i := 3 to n do
                begin
                        a := f + f1;
                        f := f1;
                        f1 := a;
                end;
        end;
        writeln(a);
end.