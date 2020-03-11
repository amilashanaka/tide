<%@ Page Language="VB" AutoEventWireup="false" CodeFile="1002.aspx.vb" Inherits="_1002" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <script type="text/javascript" src="js/jquery.min.js"></script>
    <script type="text/javascript">
        $(function () {

            var today = new Date();
            var dd = today.getDate();
            var mm = today.getMonth() ; //January is 0!
            var yyyy = today.getFullYear();
            var today_morning = new Date(yyyy, mm, dd);

            var data_height = JSON.parse("[" + document.getElementById('<%=txtdatabank.ClientID%>').value + "]");
             var data_x = JSON.parse("[" + document.getElementById('<%=txtX.ClientID%>').value + "]");

            $('#container').highcharts({
                exporting: {
                    enabled: true
                },
                chart: {
                    type: 'spline'
                },
                title: {
                    text: 'Tidal Variations ' 
                },
                xAxis: {
                 
                     showLastTickLabel: true,
                     type: 'datetime',
                      
                },
                yAxis: {
                    title: {
                        text: 'Tide Height (cm)'
                    },
                     
                    minorGridLineWidth: 0,
                    gridLineWidth: 1,
                    alternateGridColor: null

                },
                tooltip: {
                    valueSuffix: 'cm'
                },
                plotOptions: {
                    spline: {
                        lineWidth: 1,
                        states: {
                            hover: {
                                lineWidth: 1
                            }
                        },
                        marker: {
                            enabled: false
                        },
                        pointInterval: 220000,
                       pointStart: Date.now(),
                    }
                },
                series: [{
                 
                    name: 'Tide',

                    data: data_height 

                }]
            ,
                navigation: {
                    menuItemStyle: {
                        fontSize: '20px'
                    }
                }
            });
        });

      

    </script>
</head>
<body>
    <script src="js/exporting.js" type="text/javascript"></script>
    <script src="js/highcharts.js" type="text/javascript"></script>
     
    <form id="form1" runat="server">
    <div style="width: 776px; height: 345px;">
        <asp:UpdatePanel ID="HightUpdate" runat="server">
         <Triggers>
                    <asp:AsyncPostBackTrigger ControlID="Timer1" />
                </Triggers>
            <ContentTemplate>
                <asp:Timer ID="Timer1" runat="server" Interval="1000">
                </asp:Timer>
                <asp:ScriptManager ID="ScriptManager1" runat="server">
                </asp:ScriptManager>
            </ContentTemplate>
        </asp:UpdatePanel>
        <br />
        <br />
        <br />
        <div id="container" 
            
            style="min-width: 300px; height: 351px; margin: 0 auto; z-index: 1; left: 13px; top: 14px; position: absolute; width: 766px;">
            <asp:TextBox ID="txtdatabank" runat="server" 
                
                
                
                style="top: 330px; left: 4px; position: absolute; float: left; height: 19px; width: 723px"></asp:TextBox>
            <asp:TextBox ID="txtX" runat="server" Width="793px"></asp:TextBox>
        </div>
    </div>
    </form>
 
  
</body>
</html>
