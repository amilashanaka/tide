<%@ Page Language="VB" AutoEventWireup="false" CodeFile="AdminEdit.aspx.vb" Inherits="AdminEdit" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>User Home</title>

    <link rel="stylesheet" type="text/css" href="http://www.jscodes.com/codes/calendar_javascript/demo/css/datePicker.css" />
<script src="http://www.jscodes.com/codes/calendar_javascript/demo/js/jquery-1.6.1.min.js" type="text/javascript"></script>
<script src="http://www.jscodes.com/codes/calendar_javascript/demo/js/jquery.datePicker-min.js" type="text/javascript"></script>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">



    <style type="text/css">
        #datepick6
        {
            top: 267px;
            left: 486px;
            position: absolute;
            float: left;
            height:20px;
            width: 128px;
        }
        #datepick
        {
            top: 302px;
            left: 630px;
            position: absolute;
            float: left;
            height: 20px;
            width: 128px;
        }
                                                                          #datepick6
                                                                            {
                                                                                top: 304px;
                                                                                left: 481px;
                                                                                position: absolute;
                                                                                float: left;
                                                                                height: 20px;
                                                                                width: 128px;
                                                                                right: 669px;
                                                                            }
                                                                            #datepick5
                                                                            {
                                                                                top: 269px;
                                                                                left: 498px;
                                                                                position: absolute;
                                                                                float: left;
                                                                                height: 20px;
                                                                                width: 128px;
                                                                            }
        #form1
        {
            height: 104px;
            width: 814px;
        }
    </style>
        <style type="text/css">
        body
        {
            font-family: Arial;
            font-size: 10pt;
        }
        table
        {
            border: 1px solid #ccc;
            border-collapse: collapse;
            background-color: #fff;
        }
        table th
        {
            background-color: #B8DBFD;
            color: #333;
            font-weight: bold;
        }
        table th, table td
        {
            padding: 5px;
            border: 1px solid #ccc;
        }
        table, table table td
        {
            border: 0px solid #ccc;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server"><asp:label ID="lblDate" runat="server" text="" Visible="false"></asp:label>
    <br />
            <asp:GridView ID="GridView1" runat="server"  DataKeyNames="recid" OnRowDataBound="OnRowDataBound"
        OnRowEditing="OnRowEditing" OnRowCancelingEdit="OnRowCancelingEdit" OnRowUpdating="OnRowUpdating"
        OnRowDeleting="OnRowDeleting" EmptyDataText="No records has been added." AutoGenerateEditButton="true"
        AutoGenerateDeleteButton="true">
        </asp:GridView><br />
            <table border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse">
        <tr>
            <td style="width: 150px">
         
                <asp:TextBox ID="txtcrunttime" runat="server" Width="140" />
            </td>
            <td style="width: 150px">
       
                <asp:TextBox ID="txthight" runat="server" Width="140" />
            </td>
                        <td style="width: 150px">
   
                <asp:TextBox ID="txttemp" runat="server" Width="140" />
            </td>
            <td style="width: 100px">
                <asp:Button ID="btnAdd" runat="server" Text="Add"/>
            </td>
        </tr>
    </table>
<%--<asp:GridView ID="Resultview" runat="server" AutoGenerateColumns="False" 
             DataKeyNames="recid" DataSourceID="TideData" CellPadding="4" 
             ForeColor="#333333" GridLines="None" 
             style="top: -2px; left: 13px; position: relative; float: left; height: 181px" 
             Width="546px">
             <AlternatingRowStyle BackColor="White" />
             <Columns>
                 <asp:BoundField DataField="recid" HeaderText="SR No" InsertVisible="False" 
                     ReadOnly="True" SortExpression="recid" >
                 <ItemStyle HorizontalAlign="Center" />
                 </asp:BoundField>
                 <asp:BoundField DataField="crunttime" HeaderText="Time" 
                     SortExpression="crunttime" >
                 <ItemStyle HorizontalAlign="Center" />
                 </asp:BoundField>
                 <asp:BoundField DataField="hight" HeaderText="Hight in CM" 
                     SortExpression="hight" >
                 <ItemStyle HorizontalAlign="Center" />
                 </asp:BoundField>
                                  <asp:BoundField DataField="temp" HeaderText="Temp" 
                     SortExpression="temp" >
                 <ItemStyle HorizontalAlign="Center" />
                 </asp:BoundField>
             </Columns>
             <EditRowStyle BackColor="#2461BF" />
             <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
             <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
             <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
             <RowStyle BackColor="#EFF3FB" />
             <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
             <SortedAscendingCellStyle BackColor="#F5F7FB" />
             <SortedAscendingHeaderStyle BackColor="#6D95E1" />
             <SortedDescendingCellStyle BackColor="#E9EBEF" />
             <SortedDescendingHeaderStyle BackColor="#4870BE" />
         </asp:GridView>--%>
    
         <br />
     <p>&nbsp;
         </p>

     <p>
         &nbsp;</p>


        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<p>
           <asp:SqlDataSource ID="locinfo" runat="server" 
         ConnectionString="<%$ ConnectionStrings:TideConnectionString %>" 
         SelectCommand="SELECT [locName] FROM [loc]"></asp:SqlDataSource>
           </p>
     <asp:Label ID="Label1" runat="server" 
         style="top: 23px; position: absolute; float: left; height: 25px; width: 117px; right: 1147px;" 
         Text="Date :"></asp:Label>
           &nbsp;<p>
        <asp:Label ID="lblLocval" runat="server" 
            style="z-index: 1; left: 841px; top: 19px; position: absolute" Text="Label"></asp:Label>
    </p>
     <p>&nbsp;
         </p>
     <asp:Panel ID="dataPanel" runat="server" BackColor="White" 
         
         
         
         style="top: 118px; left: 950px; position: absolute; float: left; height: 43px; width: 25px">
         <asp:SqlDataSource ID="TideData" runat="server" 
             ConnectionString="<%$ ConnectionStrings:tideData %>" 
             SelectCommand="SELECT [crunttime], [hight], [recid] FROM [tideinfo]">
         </asp:SqlDataSource>
     </asp:Panel>


    </form>
</body>
</html>

