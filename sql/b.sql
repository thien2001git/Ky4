USE master create database QLCU GO

use QLCU go

create table CongTy
(			
    ID	int	not null	primary key,
    CTname	nvarchar(30),		
    addr	nvarchar(50)
)

create table SanPham
(						
    ID	int	not null	primary key,			
    SPname	nvarchar(30),					
    slc	int,					
    gia	money					
)				

create table CungUng
(						
    IDCT	int,					
    IDSP	int,					
    sl	int,					
    constraint	pk1	primary key	(IDCT,IDSP),		
    constraint	fk1	foreign key	(IDCT)	references 	CongTy(ID)	on update cascade on delete cascade,
    constraint	fk2	foreign key	(IDSP)	references 	SanPham(ID)	on update cascade on delete cascade
)

insert into CongTy values 
(	1,	'aa',	'aa1'	),
(	2,	'bb',	'bb1'	),
(	3,	'cc',	'cc1'	)

insert into SanPham values
(	1,	'qq',	15,	12000	),
(	2,	'gq',	20,	80000	),
(	3,	'ii',	25,	99000	)

insert into CungUng values 
(	1,	2,	88	),
(	3,	2,	44	),
(	2,	3,	22	),
(	1,	1,	77	),
(	2,	1,	18	)

GO
create proc show_all
as 
BEGIN
    SELECT * FROM CongTy;
    SELECT * FROM SanPham;
    SELECT * FROM CungUng;
END

exec show_all go

--
create view v_SanPhamCU as 
select SanPham.ID,SPname,sum(slc) as 'slc',sum(sl) as 'slcu' 
from SanPham inner join CungUng on SanPham.ID = CungUng.IDSP
group by SanPham.ID,SPname
GO
select * from v_SanPhamCU
GO
--

create proc nhap_ct 
    @id int,
    @name nvarchar(30),
    @addr nvarchar(50),
    @out int OUTPUT
as
begin
    if(exists(select * from CongTy WHERE CTname=@name))
    BEGIN
        set @out = 1;
        print N'Đã có công ty này';
    END
    ELSE
    begin
        set @out = 0;
        insert into CongTy values (@id,@name,@addr);
    end
END
GO
exec show_all;
GO
--sai
DECLARE @out int;
exec nhap_ct 4,'aa','cc1',@out output
select @out as 'mess'
exec show_all
go
--đúng
DECLARE @out int;
exec nhap_ct 4,'zz','cc1',@out output
select @out as 'mess'
exec show_all
GO
--

create trigger trg_u_cu
on CungUng
FOR update
as
begin
    declare @slcum int;
    declare @slcuc int;
    declare @slc int;
    declare @idsp int;
    
    select @slcum = sl from inserted;
    select @slcuc = sl from deleted;
    select @idsp = IDSP from inserted;
    select @slc = slc from SanPham WHERE ID = @idsp;

    if ((@slcum-@slcuc)<=@slc) 
    begin
        update SanPham SET slc = slc - (@slcum-@slcuc) where ID = @idsp
    end 
    else 
    begin
        RAISERROR(N'Số lượng cung ứng quá lón',16,0);
        ROLLBACK TRANSACTION;
    end
end

GO
--lỗi
exec show_all
update CungUng set sl = 999 where IDSP = 2
--không lỗi
update CungUng set sl = 5 where IDSP = 2
exec show_all