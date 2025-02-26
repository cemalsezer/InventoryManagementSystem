USE [InventoryDB]
GO
/****** Object:  Table [dbo].[Categories]    Script Date: 26.02.2025 11:39:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Categories](
	[CategoryID] [int] IDENTITY(1,1) NOT NULL,
	[CategoryName] [nvarchar](50) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[CategoryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Items]    Script Date: 26.02.2025 11:39:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Items](
	[ItemID] [int] IDENTITY(1,1) NOT NULL,
	[ItemName] [nvarchar](100) NOT NULL,
	[CategoryID] [int] NULL,
	[Quantity] [int] NOT NULL,
	[UnitPrice] [decimal](10, 2) NOT NULL,
	[LastUpdated] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[ItemID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Categories] ON 

INSERT [dbo].[Categories] ([CategoryID], [CategoryName]) VALUES (1, N'Elektronik')
INSERT [dbo].[Categories] ([CategoryID], [CategoryName]) VALUES (2, N'Mobilya')
INSERT [dbo].[Categories] ([CategoryID], [CategoryName]) VALUES (3, N'Giyim')
INSERT [dbo].[Categories] ([CategoryID], [CategoryName]) VALUES (4, N'Kitap')
SET IDENTITY_INSERT [dbo].[Categories] OFF
GO
SET IDENTITY_INSERT [dbo].[Items] ON 

INSERT [dbo].[Items] ([ItemID], [ItemName], [CategoryID], [Quantity], [UnitPrice], [LastUpdated]) VALUES (1, N'Laptop', 1, 5, CAST(15000.00 AS Decimal(10, 2)), CAST(N'2025-02-19T12:11:51.723' AS DateTime))
INSERT [dbo].[Items] ([ItemID], [ItemName], [CategoryID], [Quantity], [UnitPrice], [LastUpdated]) VALUES (2, N'Masa', 2, 12, CAST(2000.00 AS Decimal(10, 2)), CAST(N'2025-02-19T12:11:51.723' AS DateTime))
INSERT [dbo].[Items] ([ItemID], [ItemName], [CategoryID], [Quantity], [UnitPrice], [LastUpdated]) VALUES (3, N'T-shirt', 3, 50, CAST(150.00 AS Decimal(10, 2)), CAST(N'2025-02-19T12:11:51.723' AS DateTime))
INSERT [dbo].[Items] ([ItemID], [ItemName], [CategoryID], [Quantity], [UnitPrice], [LastUpdated]) VALUES (4, N'Roman Kitabi', 4, 20, CAST(1000.00 AS Decimal(10, 2)), CAST(N'2025-02-19T12:11:51.723' AS DateTime))
INSERT [dbo].[Items] ([ItemID], [ItemName], [CategoryID], [Quantity], [UnitPrice], [LastUpdated]) VALUES (6, N'Koltuk', 2, 4, CAST(2000.00 AS Decimal(10, 2)), CAST(N'2025-02-19T22:29:43.603' AS DateTime))
INSERT [dbo].[Items] ([ItemID], [ItemName], [CategoryID], [Quantity], [UnitPrice], [LastUpdated]) VALUES (7, N'Klavye', 1, 6, CAST(2000.00 AS Decimal(10, 2)), CAST(N'2025-02-21T19:26:05.147' AS DateTime))
SET IDENTITY_INSERT [dbo].[Items] OFF
GO
ALTER TABLE [dbo].[Items] ADD  DEFAULT (getdate()) FOR [LastUpdated]
GO
ALTER TABLE [dbo].[Items]  WITH CHECK ADD FOREIGN KEY([CategoryID])
REFERENCES [dbo].[Categories] ([CategoryID])
GO
/****** Object:  StoredProcedure [dbo].[sp_AddNewItem]    Script Date: 26.02.2025 11:39:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[sp_AddNewItem]
    @ItemName NVARCHAR(255),
    @CategoryID INT,
    @Quantity INT,
    @UnitPrice DECIMAL(10,2)
AS
BEGIN
    INSERT INTO Items (ItemName, CategoryID, Quantity, UnitPrice)
    VALUES (@ItemName, @CategoryID, @Quantity, @UnitPrice)
END
GO
/****** Object:  StoredProcedure [dbo].[sp_DeleteItem]    Script Date: 26.02.2025 11:39:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[sp_DeleteItem]
    @ItemID INT
AS
BEGIN
    DELETE FROM Items WHERE ItemID = @ItemID
END
GO
/****** Object:  StoredProcedure [dbo].[sp_UpdateItem]    Script Date: 26.02.2025 11:39:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[sp_UpdateItem]
    @ItemID INT,
    @ItemName NVARCHAR(255),
    @CategoryID INT,
    @Quantity INT,
    @UnitPrice DECIMAL(10,2)
AS
BEGIN
    UPDATE Items
    SET ItemName = @ItemName,
        CategoryID = @CategoryID,
        Quantity = @Quantity,
        UnitPrice = @UnitPrice
    WHERE ItemID = @ItemID
END
GO
