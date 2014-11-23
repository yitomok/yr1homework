program task8;
procedure move(disk:integer; rod1:integer; rod2:integer; rod3:integer);
begin
        if disk = 1 then
                writeln('Disk ', disk, ' from the rod ', rod1, ' to the rod ', rod2)
        else
	begin
                move(disk - 1, rod1, rod3, rod2);
		writeln('Disk ', disk, ' from the rod ', rod1, ' to the rod ', rod2);
                move(disk - 1, rod3, rod2, rod1);
	end;
end;
var disk:integer;
begin
	read(disk);
	move(disk, 1, 2, 3);
end.
