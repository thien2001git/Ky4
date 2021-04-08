/*Câu 1 (3đ): Tạo csdl QLSinhVien gồm 3 bảng:
+
Khoa MaKhoa , ten khoa
+
Lop MaLop , TenLop, SiSo,
+
SinhVien MaSV , HoTen, NgaySinh, GioiTinh(bit), MaLop
-
Tạo ràng buộc cho cột SiSo khởi tạo là 0
Nhập dữ liệu cho các bảng: 2 Khoa, 2 Lop, 7 SinhVien
*/
-- Create a new database called 'qlsinhvien'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
    SELECT name
        FROM sys.databases
        WHERE name = N'qlsinhvien'
)
CREATE DATABASE qlsinhvien
GO
use qlsinhvien
USE master DROP DATABASE qlsinhvien;

-- Create a new table called 'Khoa' in schema '
-- Drop the table if it already exists
IF OBJECT_ID('Khoa', 'U') IS NOT NULL
DROP TABLE Khoa
GO
-- Create the table in the specified schema
CREATE TABLE Khoa
(
    makhoa INT NOT NULL PRIMARY KEY, -- primary key column
    tenkhoa NVARCHAR(30) NOT NULL
    -- specify more columns here
);
GO

-- Create a new table called 'lop' in schema '
-- Drop the table if it already exists
IF OBJECT_ID('lop', 'U') IS NOT NULL
DROP TABLE lop
GO
-- Create the table in the specified schema
CREATE TABLE lop
(
    malop INT NOT NULL PRIMARY KEY, -- primary key column
    tenlop NVARCHAR(30) NOT NULL,
    siso int NOT NULL,
    CHECK (siso = 0),
    makhoa int not null,
    CONSTRAINT fk0 FOREIGN KEY (makhoa) REFERENCES khoa(makhoa) ON UPDATE CASCADE ON DELETE CASCADE

    -- specify more columns here
);
GO

-- Create a new table called 'sinhvien' in schema '
-- Drop the table if it already exists
IF OBJECT_ID('sinhvien', 'U') IS NOT NULL
DROP TABLE sinhvien
GO
-- Create the table in the specified schema
CREATE TABLE sinhvien
(
    MaSV INT NOT NULL PRIMARY KEY, -- primary key column
    HoTen NVARCHAR(30) NOT NULL,
    ngaysinh datetime NOT NULL,
    GioiTinh BIT,
    malop int not null,
    CONSTRAINT fk1 FOREIGN KEY (malop) REFERENCES lop(malop) ON UPDATE CASCADE ON DELETE CASCADE
    -- specify more columns here
);
GO

-- Insert rows into table 'khoa'
INSERT INTO khoa
( -- columns to insert data into
 makhoa,tenkhoa
)
VALUES
(1,'aa'),
(2,'bb')
-- add more rows here
GO
-- Insert rows into table 'lop'
INSERT INTO lop
( -- columns to insert data into
 malop,tenlop,siso,makhoa--[Column1], [Column2], [Column3]
)
VALUES
(1,'cc',0,1),
(2,'dd',0,2)
-- add more rows here
GO
-- Insert rows into table 'sinhvien'
INSERT INTO sinhvien
( -- columns to insert data into
 MaSV,HoTen,ngaysinh,GioiTinh,malop
)
VALUES
(1,'ee','1/1/2006',0,1),
(2,'fe','1/2/2006',0,1),
(3,'eg','1/3/2006',1,1),
(4,'ce','1/4/2006',0,2),
(5,'ev','1/5/2006',1,2),
(6,'ie','1/6/2006',0,2),
(7,'ep','1/7/2006',1,1)
-- add more rows here
GO

SELECT * FROM lop;
SELECT * FROM khoa;
SELECT * FROM sinhvien;
GO
--cau2
CREATE VIEW thongkesolop
as
    SELECT khoa.tenkhoa,COUNT(lop.malop) AS N'Số lớp'
    FROM khoa
        INNER JOIN lop ON khoa.makhoa = lop.makhoa
    GROUP BY tenkhoa
go


SELECT * FROM lop;
SELECT * FROM khoa;
SELECT * FROM sinhvien;
SELECT * FROM thongkesolop
go
--cau3
/*2đ): Viết hàm với tham số truyền vào là MaKhoa , hàm trả về
một bảng gồm các thông tin:MaSV, HoTen, NgaySinh, GioiTinh (là
Nam “ hoặc Nữ “), TenLop,*/
ALTER FUNCTION ttsinhvien(@makhoa int)
RETURNS TABLE
as
RETURN
    SELECT sinhvien.MaSV,hoten,ngaysinh,
        case when gioitinh=1 then 'Nam' else N'Nữ' end as N'Giới tính',
        tenlop
    FROM sinhvien
        INNER join lop on sinhvien.malop=lop.malop
    GROUP BY sinhvien.MaSV,hoten,ngaysinh,GioiTinh,tenlop,lop.makhoa
    HAVING lop.makhoa = @makhoa
go

SELECT * FROM lop;
SELECT * FROM khoa;
SELECT * FROM sinhvien;
SELECT * FROM dbo.ttsinhvien(2)
go
--cau 4
/*Câu 4 (3đ):
Hãy tạo thủ tục lưu trữ tìm kiếm sinh viên theo khoảng tuổi
và lớp (Với 3 tham số vào là: TuTuoi và DenTuoi và tên lớp ). Kết quả tìm
được sẽ đưa ra một danh sách gồm: MaSV, HoTen,
NgaySinh,TenLop,TenKhoa, Tuoi.*/
alter PROCEDURE tksv
@TuTuoi int,
@DenTuoi int,
@tenlop NVARCHAR(30)
as
    SELECT MaSV, HoTen,ngaysinh,tenlop,tenkhoa,YEAR(GETDATE()) - YEAR(ngaysinh) as N'Tuổi'
    from sinhvien
        INNER JOIN lop on sinhvien.malop = lop.malop
        INNER JOIN Khoa ON lop.makhoa=Khoa.makhoa
    GROUP BY MaSV, HoTen,ngaysinh,tenlop,tenkhoa,ngaysinh
    HAVING YEAR(GETDATE()) - YEAR(ngaysinh) BETWEEN @TuTuoi and @DenTuoi
        and tenlop =@tenlop

SELECT * FROM lop;
SELECT * FROM khoa;
SELECT * FROM sinhvien;
EXECUTE tksv 14, 25, 'cc'
go
/*-------------------



----------------------
*/
use master CREATE DATABASE qlbenvien;
USE qlbenvien

create TABLE benhvien
(
    mabv int not NULL PRIMARY KEY,
    tenbv NVARCHAR(30),
    diachi NVARCHAR(50),
    dienthoai CHAR(15)
)

create TABLE khoa
(
    makhoa int not NULL PRIMARY KEY,
    tenkhoa NVARCHAR(30),
    sobn int,
    mabv int not NULL,
    CONSTRAINT fk0 FOREIGN KEY (mabv) REFERENCES benhvien(mabv) ON UPDATE CASCADE ON DELETE CASCADE
)

create table benhnhan
(
    mabn int not null PRIMARY key,
    hoten NVARCHAR(30),
    gioitinh bit,
    ngaysinh DATETIME,
    songaynhap int,
    makhoa int not null,
    CONSTRAINT fk1 FOREIGN KEY (makhoa) REFERENCES khoa(makhoa) ON UPDATE CASCADE ON DELETE CASCADE
)

insert into benhvien
(mabv,tenbv,diachi,dienthoai)
VALUES
(1,'aa','aa1','0964'),
(2,'bb','bb1','0984')

insert into khoa
(makhoa,tenkhoa,sobn,mabv)
VALUES
(1,'cc',100,1),
(2,'dd',101,2)

insert into khoa
(makhoa,tenkhoa,sobn,mabv)
VALUES
(3,'uu',30,1)

insert into benhnhan
(mabn,hoten,gioitinh,ngaysinh,songaynhap,makhoa)
VALUES
(1,'ee',1,'1/1/2021',100,2),
(2,'gg',0,'7/1/2021',120,1),
(3,'ee',1,'8/1/2021',130,2),
(4,'ee',0,'2/1/2021',104,1),
(5,'ee',1,'9/1/2021',200,2)

SELECT * FROM benhvien;
SELECT * FROM khoa;
SELECT * FROM benhnhan;
GO
CREATE TRIGGER thembn
ON benhnhan
FOR insert
as 
BEGIN
    DECLARE @makhoa int;
    DECLARE @sobn int;
    select @makhoa=inserted.makhoa from inserted;
    SELECT @sobn=sobn FROM khoa WHERE makhoa =@makhoa;
    if(@sobn> 50)
    BEGIN
        RAISERROR (N'Khoa quá tải', 16 , 1);
        ROLLBACK TRANSACTION;
    END
    ELSE
        UPDATE khoa set sobn = sobn + 1 WHERE makhoa =@makhoa;
        
end

SELECT * FROM benhvien;
SELECT * FROM khoa;
SELECT * FROM benhnhan;
--không cho thêm
insert into benhnhan
(mabn,hoten,gioitinh,ngaysinh,songaynhap,makhoa)
VALUES
(8,'ee',1,'1/1/2021',100,2)
--cho thêm 
insert into benhnhan
(mabn,hoten,gioitinh,ngaysinh,songaynhap,makhoa)
VALUES
(8,'ee',1,'1/1/2021',100,3)