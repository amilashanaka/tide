<%@ Page Title="Home" Language="VB" MasterPageFile="~/Home.master" AutoEventWireup="false" CodeFile="Default.aspx.vb" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>


<asp:Content ID="Content2" runat="server" 
    contentplaceholderid="ContentPlaceHolder1">
    <p>
        <img alt="" class="style1" src="logo.jpg" 
            style="height: 130px; width: 1130px; margin-left: 136px" /></p>
    <asp:Label ID="Label1" runat="server" 
        style="top: 317px; left: 501px; position: absolute; height: 19px; width: 123px" 
        Text="Logging Name"></asp:Label>
    <asp:Label ID="Label3" runat="server" 
        style="top: 379px; left: 507px; position: absolute; height: 19px; width: 84px" 
        Text="Password"></asp:Label>
    <asp:Panel ID="Panel1" runat="server" 
        
        style="top: 267px; left: 478px; position: absolute; height: 212px; width: 445px" 
        BorderColor="Black" BorderStyle="Double" BorderWidth="5px">
        <asp:TextBox ID="TextBox1" runat="server" 
            style="top: 48px; left: 183px; position: absolute; height: 20px; width: 128px"></asp:TextBox>
        <asp:TextBox ID="TextBox2" runat="server" 
            style="top: 107px; left: 183px; position: absolute; height: 22px; width: 128px"></asp:TextBox>
    </asp:Panel>
</asp:Content>




