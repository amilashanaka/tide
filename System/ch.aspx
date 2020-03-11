<%@ Page Language="VB" AutoEventWireup="false" CodeFile="ch.aspx.vb" Inherits="ch" %>
<%@ Register Assembly="AjaxControlToolkit" Namespace="AjaxControlToolkit" TagPrefix="cc1" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Chart</title>
</head>
<body>
    <form id="form1" runat="server">
    <asp:Chart ID="Chart1" runat="server" Width="1000">
        <Series>
            <asp:Series Name="Series1" ChartType="Line" >
            </asp:Series>
        </Series>
        <ChartAreas>
            <asp:ChartArea Name="ChartArea1">
            </asp:ChartArea>
        </ChartAreas>
    </asp:Chart>
    </form>
</body>
</html>
