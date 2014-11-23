program task6;
function isPalindrom(input:string):boolean;
var i:integer;
begin
        isPalindrom := true;
        for i := 1 to length(input) div 2 do
                if input[i] <> input[length(input) - i + 1] then
                        isPalindrom := false;
end;
var input:longint;
var tmp:string;
begin
        readln(input);
        while (input <> 0) do
        begin
                str(input, tmp);
                if (isPalindrom(tmp)) then
                        write(tmp, ' ');
                readln(input);
        end;
end.
