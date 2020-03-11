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
        $(function () {
            $("#txtDate3").datepicker();

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
            top: 93px;
            position: absolute;
            height: 273px;
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
        <asp:Button ID="Button1" runat="server" Style="top: 82px; left: 88px; position: absolute;
            float: left; height: 26px; width: 153px; background-color: #F6F9FE; bottom: 372px;"
            Text="Raw Data" CssClass="style2" />
            <asp:Button ID="btnGraphGen" runat="server" 
            Style="top: 31px; left: 88px; position: absolute;
            float: left; height: 26px; width: 153px; font-weight: 700; background-color: #F6F9FE" 
            Text="Graph" />
        <h3>
            &nbsp;</h3>
        <asp:Button ID="Button8" runat="server" 
            Style="top: 425px; left: 88px; position: absolute;
            float: left; height: 26px; width: 153px; font-weight: 700; background-color: #F6F9FE" 
            Text="Log Out" />
            <asp:Button ID="Button3" runat="server" Style="top: 140px; left: 91px; position: absolute;
            float: left; height: 26px; width: 153px; background-color: #F6F9FE; bottom: 314px;"
            Text="Edit Data" CssClass="style2" />
    </asp:Panel>
    <asp:Panel ID="Panel1" runat="server" Style="top: 680px; left: -541px; position: absolute;
        float: left; height: 28px; width: 1136px; margin-left: 658px">
        <div class="style1">
            Research &amp; Development Wing</div>
    </asp:Panel>
    <asp:Panel ID="PanelOption" runat="server" BackColor="#C5D7E3" BorderColor="#0033CC"
        Style="z-index: 1; left: 457px; top: 198px; position: absolute; height: 63px;
        width: 787px">
        <asp:TextBox ID="txtDate" runat="server" Style="z-index: 1; left: 98px; top: 18px;
            position: absolute; height: 21px; margin-top: 0px;" Height="22px"></asp:TextBox>
            <asp:DropDownList ID="dpLocGp" runat="server" Style="z-index: 1; left: 392px;
                top: 19px; position: absolute">
                <asp:ListItem Value="1002">Colombo </asp:ListItem>
                <asp:ListItem Value="1003">Trincomale</asp:ListItem>
                <asp:ListItem Value="1004">Galle</asp:ListItem>
                <asp:ListItem Value="1005">KKS</asp:ListItem>
                <asp:ListItem Value="1006">oluvil</asp:ListItem>
            </asp:DropDownList>
       
        <br />
        <div class="demo">
            <b>&nbsp;Select Date :</b>
        </div>
        <b>
        <asp:Label ID="Label1" runat="server" Style="z-index: 1; left: 268px; top: 20px;
                position: absolute; height: 21px; width: 137px; right: 382px" 
            Text="Select Location :"></asp:Label>
        </b>&nbsp;
        <asp:Button ID="ButtonSmooth" runat="server" BackColor="#0066FF" Style="z-index: 1;
            left: 634px; top: 18px; position: absolute; height: 29px; width: 108px; float: left;
            border-color: #0033CC; background-color: #C5D7E3" Text="Smooth" />

               <asp:Button ID="Button2" runat="server" BackColor="#0066FF" Style="z-index: 1;
            left: 509px; top: 17px; position: absolute; height: 29px; width: 108px; float: left;
            border-color: #0033CC; background-color: #C5D7E3" Text="Genarate Graph" />
    </asp:Panel>

    <asp:Panel ID="Panelgraph" runat="server" BackColor="#C5D7E3" Style="top: 285px;
        left: 457px; position: absolute; float: left; height: 382px; width: 791px">
        <iframe id="frame1" runat="server"></iframe>
    </asp:Panel>

   
    <asp:Panel ID="PanelCalculation" runat="server" BackColor="#C5D7E3" Style="top: 193px;
        left: 457px; position: absolute; height: 68px; width: 790px">
        &nbsp;

         
        <br />
        <div class="demo">
            <b>&nbsp;Select Date :</b> 
        <asp:TextBox ID="txtDate2" runat="server" Style="z-index: 1; left: 96px; top: 18px;
            position: absolute; height: 21px;" Height="22px"></asp:TextBox>
        <br />
      
      <b>  
        <asp:Label ID="lbl2selectLocation" runat="server" Style="top: 23px; left: 259px;
            position: absolute; height: 22px; width: 135px; float: left; background-color: #C5D7E3"
            Text="Select Location :"></asp:Label></b>
        <asp:DropDownList ID="dpLoc" runat="server" Style="z-index: 1; left: 393px;
            position: absolute; height: 22px; width: 103px; float: left;
            top: 24px;">
            <asp:ListItem Value="1002">Colombo</asp:ListItem>
            <asp:ListItem Value="1003">Trincomale</asp:ListItem>
            <asp:ListItem Value="1004">Galle</asp:ListItem>
            <asp:ListItem Value="1005">KKS</asp:ListItem>
            <asp:ListItem Value="1006">Delft Jetty</asp:ListItem>
        </asp:DropDownList>
        <asp:Button ID="btnGetData" runat="server"  Style="top: 17px; left: 645px; position: absolute;
            height: 29px; width: 131px; float: left; background-color: #C5D7E3; right: 14px;" 
            Text="Get Data" />
            </div>
    </asp:Panel>
        <asp:Panel ID="PanelCalculationEdit" runat="server" BackColor="#C5D7E3" Style="top: 193px;
        left: 457px; position: absolute; height: 68px; width: 790px">
        &nbsp;

         
        <br />
        <div class="demo">
            <b>&nbsp;Select Date :</b>
        <asp:TextBox ID="txtDate3" runat="server" Style="z-index: 1; left: 96px; top: 18px;
            position: absolute; height: 21px;" Height="22px"></asp:TextBox>
        <br />
      
      <b>  
        <asp:Label ID="Label3" runat="server" Style="top: 23px; left: 259px;
            position: absolute; height: 22px; width: 135px; float: left; background-color: #C5D7E3"
            Text="Select Location :"></asp:Label></b>
        <asp:DropDownList ID="dpLoc1" runat="server" Style="z-index: 1; left: 393px;
            position: absolute; height: 22px; width: 103px; float: left;
            top: 24px;">
            <asp:ListItem Value="1002">Colombo</asp:ListItem>
            <asp:ListItem Value="1003">Trincomale</asp:ListItem>
            <asp:ListItem Value="1004">Galle</asp:ListItem>
            <asp:ListItem Value="1005">KKS</asp:ListItem>
            <asp:ListItem Value="1006">Delft Jetty</asp:ListItem>
        </asp:DropDownList>
        <asp:Button ID="btnGetData1" runat="server"  Style="top: 17px; left: 645px; position: absolute;
            height: 29px; width: 131px; float: left; background-color: #C5D7E3; right: 14px;" 
            Text="Get Data" />
             </div>
    </asp:Panel>
    <h3>
        <asp:Label ID="Label2" runat="server" Style="top: 158px; left: 166px; position: absolute;
            float: left; height: 23px; width: 56px; right: 447px" Text="Date : "></asp:Label>
        <asp:Label ID="LabelDate" runat="server" Style="top: 158px; left: 216px; position: absolute;
            float: left; height: 26px; width: 237px"></asp:Label>
    </h3>
    <asp:Panel ID="panelRealTimeMonitering" runat="server" BackColor="#C5D7E3" Style="z-index: 1;
        left: 460px; top: 287px; position: absolute; height: 372px; width: 781px">
        <iframe id="Iframe2" runat="server" onclick="return Iframe2_onclick()"></iframe>
    </asp:Panel>
    </form>
</body>
</html>
