<%@ Page Language="VB" AutoEventWireup="false" CodeFile="testdatefinal.aspx.vb" Inherits="testdatefinal" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">



    <meta charset="utf-8">
<title>jQuery UI Datepicker - Default functionality</title>
<link rel="stylesheet" href="//code.jquery.com/ui/1.11.3/themes/smoothness/jquery-ui.css">
<script src="//code.jquery.com/jquery-1.10.2.js"></script>
<script src="//code.jquery.com/ui/1.11.3/jquery-ui.js"></script>
<link rel="stylesheet" href="/resources/demos/style.css">
<script>
    $(function () {
        $("#datepicker").datepicker();
    });
</script>

<script>
    $(function () {
        $("#datapicker2").datepicker();
    });
</script>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <p>Date: <input type="text" id="datepicker"></p>
    <asp:Button ID="Button1" runat="server" style="z-index: 1; left: 349px; top: 14px; position: absolute" Text="Button" />

      <p>Date2: <input type="text" id="datapicker2"></p>

        
    </div>
    <asp:Label ID="Label1" runat="server" 
        style="z-index: 1; left: 122px; top: 157px; position: absolute" Text="Label"></asp:Label>
    <asp:Label ID="Label2" runat="server" 
        style="z-index: 1; left: 3px; top: 162px; position: absolute" Text="Label"></asp:Label>
    </form>
</body>
</html>
