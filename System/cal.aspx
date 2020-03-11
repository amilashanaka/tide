<%@ Page Language="VB" AutoEventWireup="false" CodeFile="cal.aspx.vb" Inherits="cal" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
     <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
    <script type="text/javascript">
        $(function () {

            var today = new Date();
            var dd = today.getDate();
            var mm = today.getMonth() + 1; //January is 0!
            var yyyy = today.getFullYear();
            var today_morning = new Date(yyyy, mm, dd, 0, 0, 1);

            var data_height = JSON.parse("[" + document.getElementById('<%=txtDataBank.ClientID%>').value + "]");

            $('#container').highcharts({
                exporting: {
                    enabled: true
                },
                chart: {
                    type: 'spline'
                },
                title: {
                    text: 'Tide  Graph  ' 
                },
                xAxis: {
                    type: 'datetime',
                    labels: {
                        overflow: 'justify'
                    }
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
                    valueSuffix: ' cm'
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
                       
                    }
                },
                series: [{

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
     <script src="http://code.highcharts.com/modules/exporting.js"></script>
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
    <div>

    <div id="container" 
            
            style="min-width: 300px; height: 351px; margin: 0 auto; z-index: 1; left: 13px; top: 14px; position: absolute; width: 766px;">
            <asp:TextBox ID="txtDataBank" runat="server" 
                
                
                
                style="top: 21px; left: 0px; position: absolute; float: left; height: 19px; width: 759px"></asp:TextBox>
        </div>
    
    </div>
    </form>
</body>
</html>
