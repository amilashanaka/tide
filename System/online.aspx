<%@ Page Language="VB" AutoEventWireup="false"  CodeFile="online.aspx.vb" Inherits="online"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
   <title>Online Tide Hight</title>
            <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js" 
                type="text/javascript">



</script>
            <script type="text/javascript">


                $(function () {
                    $(document).ready(function () {
                        Highcharts.setOptions({
                            global: {
                                useUTC: false
                            }
                        });

                        var chart;
                        $('#container').highcharts({
                            chart: {
                                type: 'spline',
                                animation: Highcharts.svg, // don't animate in old IE
                                marginRight: 10,
                                events: {
                                    load: function () {

                                        // set up the updating of the chart each second
                                        var series = this.series[0];
                                        setInterval(function () {
                                            var x = (new Date()).getTime(), // current time
                                            y = parseInt(document.getElementById('<%=txtHight.ClientID%>').value); //parseInt(document); //Math.random();// parent.$get("#lblTime".val()); //Math.random();
                                            series.addPoint([x, y], true, true);
                                        }, 1000);
                                    }
                                }
                            },
                            title: {
                                text: 'LIVE TIDE VARIATION'
                            },
                            xAxis: {
                                type: 'datetime',
                                tickPixelInterval: 150
                            },
                            yAxis: {
                                title: {
                                    text: 'Hight in Centimetre'
                                },
                                plotLines: [{
                                    value: 0,
                                    width: 1,
                                    color: '#808080'
                                }]
                            },
                            tooltip: {
                                formatter: function () {
                                    return '<b>' + this.series.name + '</b><br/>' +
                        Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', this.x) + '<br/>' +
                        Highcharts.numberFormat(this.y, 2);
                                }
                            },
                            legend: {
                                enabled: false
                            },
                            exporting: {
                                enabled: false
                            },
                            series: [{
                                name: 'Tide Hight',
                                data: (function () {
                                    // generate an array of random data
                                    var data = [],
                        time = (new Date()).getTime(),
                        i;

                                    for (i = -19; i <= 0; i++) {
                                        data.push({
                                            x: time + i * 1000,
                                            y: parseInt(document.getElementById('<%=txtHight.ClientID%>').value)
                                        });
                                    }
                                    return data;
                                })()
                            }]
                        });
                    });

                });
		</script>
</head>
<body>
    <script src="js/exporting.js" type="text/javascript"></script>
    <script src="js/highcharts.js" type="text/javascript"></script>
    <form id="form1" runat="server">
    <asp:Label ID="lblLoc" runat="server" Font-Bold="True" Font-Names="Times New Roman"
        Font-Size="Large" Style="top: 12px; left: 589px; position: absolute; float: left;
        height: 17px; width: 175px" Text="Location : colombo"></asp:Label>
    <div style="width: 759px">
       
        <br />
        <asp:UpdatePanel ID="HightUpdate" runat="server">
         <Triggers>
                    <asp:AsyncPostBackTrigger ControlID="TimerHight" />
                </Triggers>
            <ContentTemplate>
                <asp:Timer ID="TimerHight" runat="server" Interval="1000">
                </asp:Timer>
                <asp:Label ID="lblLocval" runat="server" 
                    style="top: 11px; left: 342px; position: absolute; float: left; height: 19px; width: 34px" 
                    Text="Label"></asp:Label>
                <asp:ScriptManager ID="ScriptManager1" runat="server">
                </asp:ScriptManager>
                <asp:Label ID="Label2" runat="server" Font-Bold="True" Style="top: 10px; left: 67px;
                    position: absolute; float: left; height: 22px; width: 144px" Text="Current Tide Level :"
                    Font-Overline="False" Font-Size="Medium"></asp:Label>
                     <asp:TextBox ID="txtHight" runat="server" 
            
            style="top: 10px; left: 217px; position: absolute; float: left; height: 22px; width: 109px" 
            BorderStyle="None"></asp:TextBox>
            </ContentTemplate>
        </asp:UpdatePanel>
        <br />
        <br />
        <div id="container" style="min-width: 300px; height: 320px; margin: 0 auto">
        </div>
    </div>
    </form>
 
  
</body>
</html>
