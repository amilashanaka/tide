<%@ Page Language="VB" AutoEventWireup="false" CodeFile="Admin.aspx.vb" Inherits="Admin" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <link type="text/css" href="css/jquery-ui-1.8.19.custom.css" rel="Stylesheet" />
    <script type="text/javascript" src="js/jquery-1.7.2.js"></script>
    <script type="text/javascript" src="js/js_jquery-1.7.2.min.js"></script>
    <script type="text/javascript" src="js/jquery-ui.js"></script>
    <title></title>
    <script type="text/javascript">
        $(function () {
            $("#txtDate").datepicker();
        });
    
    </script>
    <script type="text/javascript">
        $(function () {
            $("#txtDate2").datepicker();

        });

        function Iframe2_onclick() {

        }

    </script>
    <style type="text/css">
        .style1
        {
            text-align: center;
            height: 26px;
            background-color: #C5D7E3;
        }
        .style2
        {
            font-weight: bold;
        }
        #frame1
        {
            height: 375px;
            width: 787px;
        }
        #Iframe2
        {
            width: 774px;
            z-index: 1;
            left: 1px;
            top: 3px;
            position: absolute;
            height: 461px;
        }
    </style>
</head>
<body style="width: 997px; margin-left: 84px; height: 882px;">
    <form id="form1" runat="server">
    <h3>
        <asp:Label ID="LabelLogIn" runat="server" Style="top: 157px; left: 464px; position: absolute;
            float: left; height: 19px; width: 374px; right: 639px"></asp:Label>
    </h3>
    <asp:Image ID="Image1" runat="server" ImageUrl="~/logo.jpg" Style="top: 15px; left: 112px;
        position: absolute; float: left; height: 123px; width: 1151px" />
    <asp:Panel ID="PanelButton" runat="server" BackColor="#c5d7e3" Style="top: 192px;
        left: 114px; position: absolute; float: left; height: 480px; width: 311px">
        <asp:Button ID="Button1" runat="server" Style="top: 175px; left: 87px; position: absolute;
            float: left; height: 26px; width: 153px; background-color: #F6F9FE; bottom: 279px;"
            Text="Raw Data" CssClass="style2" />
        <asp:Button ID="Button2" runat="server" Style="top: 80px; left: 87px; position: absolute;
            float: left; height: 26px; width: 153px; font-weight: 700; background-color: #F6F9FE"
            Text="Calculation" />
        <asp:Button ID="Button3" runat="server" CssClass="style2" Style="top: 126px; left: 87px;
            position: absolute; float: left; height: 26px; width: 153px; background-color: #F6F9FE"
            Text="Report" />
        <asp:Button ID="Button4" runat="server" CssClass="style2" Style="top: 274px; left: 88px;
            position: absolute; float: left; height: 26px; width: 153px; background-color: #F6F9FE"
            Text="User Management" />
        <asp:Button ID="Button5" runat="server" CssClass="style2" Style="top: 225px; left: 86px;
            position: absolute; float: left; height: 26px; width: 155px; background-color: #F6F9FE"
            Text="DB Management" />
        <asp:Button ID="Button6" runat="server" Style="top: 31px; left: 86px; position: absolute;
            float: left; height: 26px; width: 153px; font-weight: 700; background-color: #F6F9FE"
            Text="Graph" />
        <h3>
            <asp:Button ID="Button7" runat="server" CssClass="style2" Style="top: 328px; left: 88px;
                position: absolute; float: left; height: 26px; width: 153px; background-color: #F6F9FE"
                Text="Real Time Monitoring" />
        </h3>
        <asp:Button ID="Button8" runat="server" Style="top: 376px; left: 88px; position: absolute;
            float: left; height: 26px; width: 153px; font-weight: 700; background-color: #F6F9FE"
            Text="Log Out" />
    </asp:Panel>
    <asp:Panel ID="Panel1" runat="server" Style="top: 680px; left: -541px; position: absolute;
        float: left; height: 28px; width: 1136px; margin-left: 658px">
        <div class="style1">
            R &amp; D Navy</div>
    </asp:Panel>
    <asp:Panel ID="PanelOption" runat="server" BackColor="#C5D7E3" BorderColor="#0033CC"
        Style="z-index: 1; left: 460px; top: 198px; position: absolute; height: 66px;
        width: 787px">
        <asp:TextBox ID="txtDate" runat="server" Style="z-index: 1; left: 100px; top: 15px;
            position: absolute; height: 25px;"></asp:TextBox>
        <br />
        <div class="demo">
            <b>&nbsp;Select Date :</b> </div>
         <b>   
        <asp:Label ID="Label1" runat="server" Style="z-index: 1; left: 308px; top: 23px;
                position: absolute; height: 21px; width: 137px; right: 343px" 
            Text="Select Location :"></asp:Label> </b>
            <asp:DropDownList ID="DropDownList1" runat="server" Style="z-index: 1; left: 445px;
                top: 21px; position: absolute">
                <asp:ListItem Value="1002">Rangala</asp:ListItem>
                <asp:ListItem>Trincomale</asp:ListItem>
                <asp:ListItem>NHQ</asp:ListItem>
            </asp:DropDownList>
       
        &nbsp;
        <asp:Button ID="ButtonDone" runat="server" BackColor="#0066FF" Style="z-index: 1;
            left: 598px; top: 18px; position: absolute; height: 29px; width: 132px; float: left;
            border-color: #0033CC; background-color: #C5D7E3" Text="Genarate Graph" />
    </asp:Panel>

    <asp:Panel ID="Panelgraph" runat="server" BackColor="#C5D7E3" Style="top: 285px;
        left: 457px; position: absolute; float: left; height: 382px; width: 791px">
        <iframe id="frame1" runat="server"></iframe>
    </asp:Panel>

   
    <asp:Panel ID="PanelCalculation" runat="server" BackColor="#C5D7E3" Style="top: 193px;
        left: 457px; position: absolute; height: 74px; width: 790px">
        &nbsp;

         
        <br />
        <div class="demo">
            <b>&nbsp;Select Date :</b> </div>
        <asp:TextBox ID="txtDate2" runat="server" Style="z-index: 1; left: 111px; top: 20px;
            position: absolute"></asp:TextBox>
        <br />
      
      <b>  
        <asp:Label ID="lbl2selectLocation" runat="server" Style="top: 20px; left: 307px;
            position: absolute; height: 22px; width: 135px; float: left; background-color: #C5D7E3"
            Text="Select Location :"></asp:Label></b>
        <asp:DropDownList ID="DropDownList2" runat="server" Style="z-index: 16px; left: 434px;
            position: absolute; height: 20px; width: 110px; float: left; background-color: #C5D7E3;
            top: 21px;">
            <asp:ListItem>Rangala</asp:ListItem>
            <asp:ListItem>NHQ</asp:ListItem>
            <asp:ListItem>Trincomale</asp:ListItem>
        </asp:DropDownList>
        <asp:Button ID="Button9" runat="server" Style="top: 19px; left: 604px; position: absolute;
            height: 29px; width: 131px; float: left; background-color: #C5D7E3" 
            Text="Get Data" />
    </asp:Panel>
    <h3>
        <asp:Label ID="Label2" runat="server" Style="top: 158px; left: 166px; position: absolute;
            float: left; height: 23px; width: 56px; right: 447px" Text="Date : "></asp:Label>
        <asp:Label ID="LabelDate" runat="server" Style="top: 158px; left: 216px; position: absolute;
            float: left; height: 26px; width: 237px"></asp:Label>
    </h3>
    <asp:Panel ID="panelRealTimeMonitering" runat="server" BackColor="#C5D7E3" Style="z-index: 1;
        left: 460px; top: 196px; position: absolute; height: 463px; width: 781px">
        <iframe id="Iframe2" runat="server" onclick="return Iframe2_onclick()"></iframe>
    </asp:Panel>
    </form>
</body>
</html>
