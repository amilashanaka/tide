<%@ Page Language="VB" AutoEventWireup="false" CodeFile="Logging.aspx.vb" Inherits="Logging" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <script src="https://maps.googleapis.com/maps/api/js?v=3.exp"></script>
    <style>
        #map-canvas
        {
            height: 126%;
            margin: 0px;
            padding: 0px;
        }
    </style>
     
    <script>
        
        var map;
        function initialize() {
            var mapOptions = {
                zoom: 7,
                center: new google.maps.LatLng(7.832225, 80.557752)
            };

            var map = new google.maps.Map(document.getElementById('map-canvas'),
      mapOptions);

            var marker = new google.maps.Marker({
                position: new google.maps.LatLng(6.937644, 79.841588),
                map: map,
                title: 'Colombo'
            });



            google.maps.event.addListener(marker, 'click', function () {
                (document.getElementById('<%=txtloc.ClientID%>')).value = 1;

                document.getElementById('<%= pnlInfo.ClientID %>').style.visibility = 'visible';
                document.getElementById('<%= pnlInfo.ClientID %>').innerHTML = '<object width="100%" height="100%" type="text/aspx" data="online.aspx"></object>';
            });

        }

        google.maps.event.addDomListener(window, 'load', initialize);

    </script>
    <title></title>
    <style type="text/css">
        .style1
        {
            width: 1192px;
            height: 104px;
        }
    </style>
    <script language="javascript" type="text/javascript">
// <![CDATA[

        function window_onload() {

        }

// ]]>
    </script>
</head>
<body onload="return window_onload()" style="margin-left: 150px">
    <form id="frmLogging" runat="server" title="SLN TIDE MONITORING SYSTEM">
    <p style="top: 15px; left: 67px; position: absolute; float: left; height: 130px;
        width: 1209px">
        <img alt="" class="style1" src="logo.jpg" style="height: 119px; width: 1130px; margin-left: 13px" />
    </p>
    <div style="margin-left: 136px">
        <asp:Label ID="lblDate" runat="server" Style="top: 169px; left: 133px; position: absolute;
            float: left; height: 15px; width: 164px; margin-top: 2px; right: 877px;"></asp:Label>
    </div>
    <asp:Button ID="btnLogging" runat="server" Style="top: 157px; left: 1108px; position: absolute;
        float: left; height: 24px; width: 98px; margin-top: 5px" Text="Logging" BorderStyle="Solid" />
    <asp:Panel ID="LogPanel" runat="server" BackImageUrl="~/Untitled-1.png" BorderStyle="Double"
        Style="top: 323px; left: 532px; position: absolute; float: left; height: 200px;
        width: 300px" Font-Bold="True" HorizontalAlign="Center">
        <asp:Label ID="DtOff9" runat="server" Font-Bold="False" Font-Italic="False" Font-Size="Medium"
            Style="top: 56px; left: -103px; position: absolute; float: left; height: 17px;
            width: 120px; margin-left: 139px; text-align: left;" Text="User Name"></asp:Label>
        <asp:Label ID="DtOff10" runat="server" Font-Bold="False" Font-Italic="False" Font-Size="Medium"
            Style="top: 97px; left: -105px; position: absolute; float: left; height: 17px;
            width: 120px; margin-left: 139px; text-align: left;" Text="Password"></asp:Label>
        <asp:Button ID="btnlogsub" runat="server" CssClass="style1" Style="top: 155px; left: 188px;
            position: absolute; float: left; height: 26px; width: 102px" Text="Log In" BackColor="#3399FF"
            BorderStyle="Groove" />
        <asp:TextBox ID="txtpass" runat="server" Style="top: 99px; left: 145px; position: absolute;
            height: 19px; width: 128px" TextMode="Password"></asp:TextBox>
        <asp:TextBox ID="txtusrName" runat="server" Style="top: 56px; left: 145px; position: absolute;
            height: 19px; width: 128px"></asp:TextBox>
        <asp:Label ID="DtOff8" runat="server" BackColor="#3399FF" BorderStyle="None" Font-Bold="False"
            Font-Italic="False" Font-Size="Medium" Style="top: 0px; left: -139px; position: absolute;
            float: left; height: 23px; width: 300px; margin-left: 139px; text-align: center;"
            Text="Log In"></asp:Label>
    </asp:Panel>
    <p>
        &nbsp;</p&nbsp;</p>
    <p style="text-align: left">
        <asp:Label ID="lblLog" runat="server" Font-Bold="False" Font-Italic="False" Font-Size="Medium"
            Style="top: 166px; left: 720px; position: absolute; float: left; height: 17px;
            width: 223px; margin-left: 139px; text-align: left;"></asp:Label>
        <asp:Label ID="Label2" runat="server" Style="top: 170px; left: 78px; position: absolute;
            float: left; height: 19px; width: 44px" Text="&nbsp;Date : "></asp:Label>
    <asp:Panel ID="pnlMap" runat="server" BackColor="#66FFFF" ForeColor="#0000CC" Style="top: 209px;
        left: 78px; position: absolute; float: left; height: 340px; width: 286px">
        <div id="map-canvas">
        </div>
    </asp:Panel>
    <asp:Panel ID="pnlInfo" runat="server" BackColor="White" 
        
        Style="top: 211px; left: 381px;
        position: absolute; float: left; height: 423px; width: 827px; z-index: -1;">
       
    </asp:Panel>
    <p>
        <asp:Label ID="lbllocation" runat="server" 
            
            
            
            
            style="top: 172px; left: 288px; position: absolute; float: left; height: 18px; width: 22px; right: 885px;">ID: </asp:Label>
    <asp:TextBox ID="txtloc" runat="server" 
        
            style="top: 172px; left: 325px; position: absolute; float: left; height: 12px; width: 39px"></asp:TextBox>
    </form>
</body>
</html>
