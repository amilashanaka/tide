<%@ Page Language="VB" AutoEventWireup="false" CodeFile="demo.aspx.vb" Inherits="demo" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta http-equiv="X-UA-Compatible" content="IE=EmulateIE7" />
<title>A Colorful Clock With CSS &amp; jQuery | Tutorialzine demo</title>

<link rel="stylesheet" type="text/css" href="styles.css" />
<link rel="stylesheet" type="text/css" href="jquery.tzineClock/jquery.tzineClock.css" />

<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.min.js"></script>
<script type="text/javascript" src="jquery.tzineClock/jquery.tzineClock.js"></script>

<script type="text/javascript" src="script.js"></script>


   
</head>
<body bgcolor="#ffffff">
    <form id="form1" runat="server">
    
    
        <asp:Panel ID="Panel2" runat="server" BackColor="#FFCC00" 
            style="z-index: 1; left: 282px; top: 86px; position: absolute; height: 263px; width: 442px">
            <div id="fancyClock"></div> 
        </asp:Panel>
  
    </form>
</body>
</html>
