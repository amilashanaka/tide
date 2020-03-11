<%@ Page Language="VB" AutoEventWireup="false" CodeFile="test.aspx.vb" Inherits="test" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>


    <style type="text/css">

        .style1
        {
            width: 1192px;
            height: 104px;
        }
    </style>
    <script language="javascript" type="text/javascript"/>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
    <asp:Panel ID="Panel1" runat="server" BackColor="#99CCFF" Height="247px">




    </asp:Panel>

    <asp:UpdatePanel ID="HightUpdate" runat="server">
                <Triggers>
                    <asp:AsyncPostBackTrigger ControlID="Timer1" />
                </Triggers>
                <ContentTemplate>
                    <br />
                    <asp:Label ID="lblTime" runat="server" ClientIDMode="Static" 
                        
                        style="top: 18px; left: 102px; position: absolute; float: left; height: 18px; width: 109px"></asp:Label>
                    <asp:TextBox ID="txtsample" runat="server" ClientIDMode="Static" 
                        BorderStyle="None" 
                        
                        
                        
                        
                        style="top: 24px; left: 389px; position: absolute; float: left; height: 20px; width: 63px"></asp:TextBox>
                    <asp:Timer ID="Timer1" runat="server" Interval="1000" >
                    </asp:Timer>
                    <asp:ScriptManager ID="ScriptManager1" runat="server">
                    </asp:ScriptManager>
                </ContentTemplate>
            </asp:UpdatePanel>


         
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
                                            y = parseInt(document.getElementById('<%=txtsample.ClientID%>').value); //parseInt(document); //Math.random();// parent.$get("#lblTime".val()); //Math.random();
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
                                            y: parseInt(document.getElementById('<%=txtsample.ClientID%>').value)
                                        });
                                    }
                                    return data;
                                })()
                            }]
                        });
                    });

                });
		</script>
            <br></br>
            </br>
        </br>
		</head>
	<body>
<script src="js/highcharts.js"></script>
<script src="js/modules/exporting.js"></script>


    </form>
</body>
</html>
