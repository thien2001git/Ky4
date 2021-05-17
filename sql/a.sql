USE master create database QLBH;

use QLBH;
drop database QLBH;
create table HangSX 
(  
    MaHangSX int primary key not null,
    TenHang nvarchar(30)  ,
    DiaChi nvarchar(30)  ,
    SoDT char(20)  ,
    Email nvarchar(30)  
)

create table SanPham
(
    MaSP int  not null ,
    MaHangSX int  not null ,
    TenSP nvarchar(30)  , 
    SoLuong int,
    MauSac nvarchar(30)  , 
    GiaBan money,
    DonViTinh nvarchar(30)  , 
    MoTa nvarchar(30)  , 
    constraint pk1 primary key (MaSP) ,
    constraint fk2 foreign key (MaHangSX) references HangSX(MaHangSX) on update cascade on delete cascade
)

create table NhanVien   
(
    MaNV int primary key not null,
    TenNV nvarchar(30),  
    GioiTinh bit,  
    DiaChi nvarchar(50),  
    SoDT char(20),  
    Email nvarchar(30),  
    TenPhong nvarchar(30)  
)

create table Nhap 		
(				
    SoHDN	int		not null,			
    MaSP	int		not null,			
    SoLuongN	int,					
    DonGiaN	money,					
    constraint	pk3	primary key	(MaSP,SoHDN),			
    constraint	fk4	foreign key	(MaSP)	references SanPham(MaSP)	on update cascade on delete cascade

)


create table PNhap		
(				
    SoHDN	int,					
    NgayNhap	datetime,					
    MaNV	int,					
    constraint	fk5	foreign key	(MaNV)	references 	NhanVien(MaNV)	on update cascade on delete cascade
)
alter table PNhap alter column SoHDN int not null
alter table PNhap add primary key (SoHDN)

create table Xuat			
(			
    SoHDX	int		not null,			
    MaSP	int		not null,			
    SoLuongX	int,					
    constraint	pk6	primary key	(MaSP,SoHDX),			
    constraint	fk7	foreign key	(MaSP)	references 	SanPham(MaSP)	on update cascade on delete cascade
)


create table PXuat	
(					
    SoHDX	int,					
    NgayXuat	datetime,					
    MaNV	int,					
    constraint	fk8	foreign key	(MaNV)	references 	NhanVien(MaNV)	on update cascade on delete cascade
)
alter table PXuat alter column SoHDX int not null
alter table PXuat add primary key (SoHDX)


--A 

-- Insert rows into table 'TableName'
INSERT INTO HangSX
VALUES
(1,'Samsung','Korea','011-08271717','ss@gmail.com.kr'),
(2,'OPPO','China','081-08626262','oppo@gmail.com.cn'),
(3,'Vinfone',N'Việt nam','084-098262626','vf@gmail.com.vn')
-- add more rows here
GO

INSERT INTO NhanVien
VALUES
(1,N'Nguyễn ThịThu',0,N'Hà Nội','0982626521','thu@gmail.com',N'Kế toán'),
(2,N'Lê Văn Nam',1,N'Bắc Ninh','0972525252','nam@gmail.com',N'Vật tư'),
(3,N'Trần Hòa Bình',0,N'Hà Nội','0328388388','hb@gmail.com',N'Kế toán')

INSERT INTO SanPham
VALUES 
(1,2,'F1 Plus',100,N'Xám',7000000,N'Chiếc',N'Hàng cận cao cấp'),
(2,1,'Galaxy Note',1150,N'Đỏ',19000000,N'Chiếc',N'Hàng cao cấp'),
(3,2,'F3 lite',200,N'Nâu',3000000,N'Chiếc',N'Hàng phổthông'),
(4,3,'Vjoy',3200,N'Xám',1500000,N'Chiếc',N'Hàng phổthông'),
(5,1,'Galaxy V21',500,N'Nâu',8000000,N'Chiếc',N'Hàng cận cao cấp')


INSERT INTO PNhap
VALUES
(1,'02-05-2019',1),
(2,'04-07-2020',2),
(3,'05-17-2020',2),
(4,'03-22-2020',3),
(5,'07-07-2020',1)


INSERT INTO Nhap
VALUES
(1 ,	2 ,	10 ,	17000000 ),
(2 ,	1 ,	30 ,	6000000 ),
(3 ,	4 ,	20 ,	1200000 ),
(4 ,	1 ,	10 ,	6200000 ),
(5 ,	5 ,	20 ,	7000000 )

INSERT INTO PXuat
VALUES
(1 ,	'06-14-2020' ,	2),
(2 ,	'03-05-2019' ,	3),
(3 ,	'12-12-2020' ,	1),
(4 ,	'06-02-2020' ,	2),
(5 ,	'05-18-2020' ,	1)

INSERT INTO Xuat
VALUES
(1 ,	3 ,	5 ),
(2 ,	1 ,	3 ),
(3 ,	2 ,	1 ),
(4 ,	3 ,	2 ),
(5 ,	5 ,	1 )


-- Create a new stored procedure called 'show' in schema '
-- Drop the stored procedure if it already exists
IF EXISTS (
SELECT *
    FROM INFORMATION_SCHEMA.ROUTINES
WHERE SPECIFIC_SCHEMA = N''
    AND SPECIFIC_NAME = N'show'
)
DROP PROCEDURE show
GO
-- Create the stored procedure in the specified schema
CREATE PROCEDURE show
AS
    Select* From SanPham;
    Select* From HangSX;
    Select* From NhanVien;
    Select * From PNhap;
    Select* From Nhap;
    Select * From PXuat;
    Select* From Xuat;
GO
-- example to execute the stored procedure we just created
EXECUTE show 
GO

--view
create view SanPhamGiamDan as
Select MaSP, TenSP, TenHang,SoLuong, MauSac, GiaBan, DonViTinh, MoTa
From SanPham Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
GO
select * from SanPhamGiamDan Order by GiaBan desc;
GO

create view SanPhamSamSung as
Select MaSP, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
From SanPham Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
Where TenHang = 'Samsung'
GO
select * from SanPhamSamSung
GO


--nhân viên Nữ ở phòng 'Kế toán'.
create view NVNuKeToan as
Select * From NhanVien
Where GioiTinh = 0 And TenPhong = N'Kế toán'
GO
select * from NVNuKeToan
GO


--
create view NhapSP as
Select PNhap.SoHDN, SanPham.MaSP, TenSP, TenHang, SoLuongN, DonGiaN, SoLuongN*DonGiaN As N'Tiền nhập', MauSac, DonViTinh, NgayNhap, TenNV, TenPhong
From Nhap Inner join SanPham on Nhap.MaSP = SanPham.MaSP
    Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
    Inner join NhanVien on PNhap.MaNV = NhanVien.MaNV
    Inner join HangSX on HangSX.MaHangSX=SanPham.MaHangSX
GO
select * from NhapSP Order by SoHDN ASC
GO

--xuất sp trong tháng 06 năm 2020
create view XuatSP as
Select Xuat.SoHDX, SanPham.MaSP, TenSP, TenHang, SoLuongX, GiaBan, SoLuongX*GiaBan As N'Tiền xuất', MauSac, DonViTinh, NgayXuat, TenNV, TenPhong
From Xuat Inner join SanPham on Xuat.MaSP = SanPham.MaSP
    Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
    Inner join NhanVien on PXuat.MaNV = NhanVien.MaNV
    Inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
Where Month(NgayXuat)=06 And Year(NgayXuat)=2020
GO
select * from XuatSP
go

--Samsung đã nhập trong năm 2020
create view Samsung2020 as
Select Nhap.SoHDN, SanPham.MaSP, TenSP, SoLuongN, DonGiaN, NgayNhap, TenNV, TenPhong
From Nhap Inner join SanPham on Nhap.MaSP = SanPham.MaSP
    Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
    Inner join NhanVien on PNhap.MaNV = NhanVien.MaNV
    Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
Where TenHang = 'Samsung' And Year(NgayNhap)= 2020
GO
select * from Samsung2020
GO

--Top 10 hóa đơn xuất
create view top10_2020 as
Select Top 10 Xuat.SoHDX, NgayXuat, SoLuongX
From Xuat Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
Where Year(NgayXuat)=2020
GO
select * from top10_2020 Order by SoLuongX DESC
GO

--10 sản phẩm có giá bán cao nhất
create view top_giaBan as 
Select top 10 MaSP, TenSP,GiaBan
From SanPham
GO
select * from top_giaBan Order by GiaBan DESC
GO

--tổng tiền đã xuất trong ngày 14/06/2020.
create view tt_14062020 as
Select Sum(SoLuongX*GiaBan) As N'Tổng tiền xuất'
From Xuat Inner join SanPham on Xuat.MaSP = SanPham.MaSP
Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
Where NgayXuat = '06/14/2020'
GO
select * from tt_14062020
go

--SoHDN, NgayNhap có tiền nhập phải trả cao nhất trong năm 2020.
create view max_2020 as
Select Nhap.SoHDN,NgayNhap
From Nhap Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
Where Year(NgayNhap)=2020 And SoLuongN*DonGiaN =
    (
        Select Max(SoLuongN*DonGiaN)
        From Nhap Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
        Where Year(NgayNhap)=2020
    )
GO
select * from max_2020
GO

--so luong nhap cao nhat 2019
create view slnMax_2019 as
select top 1 Nhap.MaSP, TenSP from SanPham
    Inner join Nhap on Nhap.MaSP = SanPham.MaSP
    Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
where YEAR(NgayNhap) = 2019
go
select * from slnMax_2019
go

-- 
create view nv01_Samsung as
select SanPham.MaSP, SanPham.TenSP from SanPham
    Inner join Nhap on Nhap.MaSP = SanPham.MaSP
    Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
    Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
where MaNV = 1 And TenHang = 'Samsung'
GO
select * from nv01_Samsung
GO

-- 
create view sp02_nv02 as 
select PNhap.SoHDN,SanPham.MaSP,SoLuongN,NgayNhap
from SanPham
    Inner join Nhap on Nhap.MaSP = SanPham.MaSP
    Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
where MaNV = 2 and SanPham.MaSP = 2
GO
select * from sp02_nv02
go

--manv,TenNV đã xuất mặt hàng có mã 'SP02' ngày '03-02-2020'
create view sp02_03022020_x as 
select NhanVien.MaNV, TenNV from NhanVien
    Inner join PNhap on PNhap.MaNV=NhanVien.MaNV
    inner join Nhap on Nhap.SoHDN = PNhap.SoHDN
where MaSP = 2 and NgayNhap = '03-02-2020' 
GO
select * from sp02_03022020_x
go

--Đưa ra tên HangSX khi nhập vào MaSP từ bàn phím
Create Function HangSX_for_MaSP (@masp nvarchar(30))
returns nvarchar(30) 
as
BEGIN
    DECLARE @hang nvarchar(30)
    set @hang =
    (
        select TenHang from SanPham 
            inner join HangSX on HangSX.MaHangSX = SanPham.MaHangSX
        where MaSP = @masp
    ) 
    return @hang
END
GO
select dbo.HangSX_for_MaSP(5) as 'Tên Hãng'
go

--thông tin các sản phẩm của hãng có tên nhập từ bàn phím.
CREATE function ttsp(@ten nvarchar(30))
returns @b table 
(
    MaSP	int,
    MaHangSX	int,
    TenSP	nvarchar(30),
    SoLuong	int,
    MauSac	nvarchar(30),
    GiaBan	money,
    DonViTinh	nvarchar(30),
    MoTa	nvarchar(30)
) as 
begin
    INSERT INTO @b 
        SELECT SanPham.MaSP,
            HangSX.MaHangSX,
            TenSP,
            SoLuong,
            MauSac,
            GiaBan,
            DonViTinh,
            MoTa
        FROM SanPham Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
        WHERE TenHang = @ten
    return
end	
GO
select * from dbo.ttsp('Samsung')
go

-- Create a new stored procedure called 'NhapHangSX' in schema '
-- Drop the stored procedure if it already exists
IF EXISTS (
SELECT *
    FROM INFORMATION_SCHEMA.ROUTINES
WHERE SPECIFIC_SCHEMA = N''
    AND SPECIFIC_NAME = N'NhapHangSX'
)
DROP PROCEDURE NhapHangSX
GO
-- Create the stored procedure in the specified schema
CREATE PROCEDURE NhapHangSX
    @MaHangSX	int,
    @TenHang	nvarchar(30),
    @DiaChi	nvarchar(30),
    @SoDT	char(20),
    @Email	nvarchar(30)
AS
    if exists (select * from HangSX where TenHang = @TenHang) 
        print 'Đã có hãng này'
    ELSE
        INSERT INTO HangSX values
        (
            @MaHangSX,
            @TenHang,
            @DiaChi,
            @SoDT,
            @Email
        )
GO
-- example to execute the stored procedure we just created
-- lỗi
EXECUTE NhapHangSX 6,'Samsung',N'Hàn Quốc','12345678','ex1@gmail.com'
GO
-- ko lỗi
EXECUTE NhapHangSX 6,'Iphone',N'Hàn Quốc','12345678','ex1@gmail.com'
GO


--Tạo Trigger kiểm soát việc nhập dữ liệu cho bảng nhập, hãy kiểm tra các ràng buộc toàn vẹn: 
--MaSP có trong bảng sản phẩm chưa? 
--Kiểm tra các ràng buộc dữ liệu: SoLuongN và DonGiaN>0

-- Sau khi nhập thì SoLuong ở bảng SanPham sẽ được cập nhật theo.
create proc show1
as 
begin
    print N'Không có sản phẩm'
end

go

alter trigger tNhap on Nhap 
for INSERT
as
begin
    declare @masp int  
    declare @sln int 
    declare @dgn money 
    select @masp=MaSP,@sln = SoLuongN,@dgn =DonGiaN from inserted

    if (exists(select * from SanPham where MaSP =@masp) )
    begin
        if(@sln<=0 or @dgn <=0) 
        begin
            RAISERROR (N'Số lượng hoặc đơn giá nhập nhỏ hơn không!',16,99)
            ROLLBACK TRANSACTION
        end
        ELSE
            update SanPham set SoLuong=SoLuong+@sln where MaSP = @masp
        return
    end

    else
    begin
        EXECUTE show1
        RAISERROR (N'Không có sản phẩm trong Bảng sản phẩm. Đó là sản phẩm mới?',16,0)
        ROLLBACK TRANSACTION
        return
    end
    
end
go
-- lỗi 1
insert into Nhap values (2,8,5,15000000)
--lỗi 2
insert into Nhap values (2,2,-5,15000000)
insert into Nhap values (2,5,5,-15000000)
--không lỗi
insert into Nhap values (2,5,5,15000000)
execute show
drop trigger tNhap




go
alter Trigger trg_Nhap
On Nhap
For Insert
As
Begin
    Declare @MaSP int
    Declare @sln int, @dgn money
    Select @MaSP=MaSP,@sln=SoLuongN,@dgn = DonGiaN From Inserted

    If(Not Exists(Select * From SanPham Where MaSP = @MaSP))
    Begin
        Raiserror(N'Không tồn tại sản phẩm trong danh mục sản phẩm',16,1)
        Rollback Transaction
    End
    Else If(@sln<=0 Or @dgn<=0)
    Begin
        Raiserror(N'Nhập sai SoLuong hoặc DonGia',16,1)
        Rollback Transaction
    End
    Else -- Bây giờ mới được phép nhập, khi này cần thay đổi SoLuong --trong bảng SanPham
        Update SanPham Set SoLuong = SoLuong + @sln
    From SanPham Where MaSP = @MaSP
End
--◼ Thực thi Trigger:
-- Gọi dữ liệu 3 bảng liên quan
Select * From SanPham
Select * From NhanVien
Select * From Nhap
-- Nhập sai:
Insert Into Nhap Values(4,7, 0,1500000)
-- Nhập đúng:
Insert Into Nhap Values(1,1, 300,1500000)
Select * From nhap
Select * From SanPham