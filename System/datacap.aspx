<%@ Page Language="VB" AutoEventWireup="false" CodeFile="datacap.aspx.vb" Inherits="datacap" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
    <asp:Label ID="lblHight" runat="server" 
        style="top: 56px; left: 13px; position: absolute; float: left; height: 23px; width: 98px" 
        Text="Hight"></asp:Label>
    <p>
        <asp:Label ID="lbltemp" runat="server" 
            style="top: 54px; left: 84px; position: absolute; float: left; height: 19px; width: 111px" 
            Text="Tempecture "></asp:Label>
    </p>
    <asp:Label ID="lbldatetime" runat="server" 
        style="top: 55px; left: 191px; position: absolute; float: left; height: 19px; width: 143px" 
        Text="DateTime"></asp:Label>
    </form>
</body>
</html>
