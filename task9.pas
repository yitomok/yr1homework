program task9;
var numOfDay:array[1..12] of integer;
var day, month, year:integer;
begin
        read(day);
        read(month);
        read(year);
	numOfDay[1] := 31;
        if ((year mod 4 = 0) and (year mod 100 <> 0)) or (year mod 400 = 0) then
		numOfDay[2] := 29
        else
		numOfDay[2] := 28;
	numOfDay[3] := 31;
	numOfDay[4] := 30;
	numOfDay[5] := 31;
	numOfDay[6] := 30;
	numOfDay[7] := 31;
	numOfDay[8] := 31;
	numOfDay[9] := 30;
	numOfDay[10] := 31;
	numOfDay[11] := 30;
	numOfDay[12] := 31;

        if day + 1 > numOfDay[month] then
		if month = 12 then
			write('1 1 ', year + 1)
		else
			write('1 ', month + 1, ' ', year)
	else
		write(day + 1, ' ', month, ' ', year);
end.
