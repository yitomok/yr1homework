program task12;
type nodeptr=^node;
node=record
        val:longint;
        next:nodeptr;
        end;
var tmp,root:nodeptr;
begin
        new(root);
        tmp:=root;
        read(tmp^.val);
        tmp^.next:=nil;

        while not eof do
        begin
                new(tmp^.next);
                tmp^.next^.next:=nil;
                read(tmp^.next^.val);
                if not eof then
                        tmp:=tmp^.next
                else
                begin
                        dispose(tmp^.next);
                        tmp^.next:=nil;
                end;
        end;

	tmp:=root;
	while tmp<> nil do
	begin
		writeln(tmp^.val);
		tmp:=tmp^.next;
	end;
        while root<>nil do
        begin
                tmp:=root;
                writeln(tmp^.val);
                root:=tmp^.next;
                dispose(tmp);
        end;
end.
