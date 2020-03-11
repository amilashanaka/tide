<%@ Page Language="VB" AutoEventWireup="false" CodeFile="testdate.aspx.vb" Inherits="testdate.aspx" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"><html xmlns="http://www.w3.org/1999/xhtml">
<head runat=server >
<title>jQuery UI Datepicker - Default functionality</title>
<meta charset="utf-8">
<title>jQuery UI Datepicker - Default functionality</title>
<link rel="stylesheet" href="//code.jquery.com/ui/1.11.3/themes/smoothness/jquery-ui.css"/>
<script src="//code.jquery.com/jquery-1.10.2.js"></script>
<script src="//code.jquery.com/ui/1.11.3/jquery-ui.js"></script>
<link rel="stylesheet" href="/resources/demos/style.css" />
<script>
    $(function () {
        $("#datepicker").datepicker();
    });
</script>

<script>
    $(function () {
        $("#datepicker2").datepicker();
    });
    function datepicker2_onclick() {

    }

</script>
</head>

<body>
    <form id="form1" runat="server">
<p>Date: <input type="text" id="datepicker">
    </p>


    <p>Date2: <input type="text" id="datepicker2" onclick="return datepicker2_onclick()">
    </p>

    <asp:Button ID="done" runat="server" Text="Done" />
    <asp:Label ID="Label1" runat="server" 
        style="z-index: 1; left: 15px; top: 205px; position: absolute" Text="Label"></asp:Label>
    <asp:Label ID="Label2" runat="server" 
        style="z-index: 1; left: 15px; top: 248px; position: absolute" Text="Label"></asp:Label>

    </form>
</body>
</html>