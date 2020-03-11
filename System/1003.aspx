<%@ Page Language="VB" AutoEventWireup="false" CodeFile="1003.aspx.vb" Inherits="_1003" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

 <!DOCTYPE HTML>
<!DOCTYPE HTML>
<html>

<head>  
  <script type="text/javascript">
      window.onload = function () {
          var chart = new CanvasJS.Chart("chartContainer",
    {
        title: {
            text: "Twitter Mentions for iPhone and Samsung"
        },
        animationEnabled: true,
        axisY: {
            includeZero: false
        },
        toolTip: {
            shared: "true"
        },
        data: [
      {
          type: "spline",
          showInLegend: true,
          name: "mentions of iPhone",
          markerSize: 0,
          dataPoints: [
        { x: new Date(2013, 4, 1), y: 430576 },
        { x: new Date(2013, 4, 2), y: 498157 },
        { x: new Date(2013, 4, 3), y: 415128 },
        { x: new Date(2013, 4, 4), y: 342031 },
        { x: new Date(2013, 4, 5), y: 320376 },
        { x: new Date(2013, 4, 6), y: 405322 },
        { x: new Date(2013, 4, 7), y: 433426 },
        { x: new Date(2013, 4, 8), y: 430876 },
        { x: new Date(2013, 4, 09), y: 372277 },
        { x: new Date(2013, 4, 10), y: 351863 },
        { x: new Date(2013, 4, 11), y: 281959 },
        { x: new Date(2013, 4, 12), y: 282666 },
        { x: new Date(2013, 4, 13), y: 353718 },
        { x: new Date(2013, 4, 14), y: 507833 }
        ]
      },
      
      ]
    });

          chart.render();
      }
</script>
<script type="text/javascript" src="js/canvasjs.min.js"></script>
</head>
<body>
  <div id="chartContainer" style="height: 300px; width: 100%;">
  </div>
</body>
</html>
