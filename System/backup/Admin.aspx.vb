
Partial Class Admin
    Inherits System.Web.UI.Page

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

	

        LabelDate.Text = System.DateTime.Now.ToString("dd MMMM yyyy")

        Dim welcomeText As String

        welcomeText = Request.QueryString("id")

        PanelOption.Visible = False
        Panelgraph.Visible = False
        PanelCalculation.Visible = False
        panelRealTimeMonitering.Visible = False


        LabelLogIn.Text = "WelCome  &nbsp " + welcomeText



    End Sub

 

    Protected Sub Button6_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button6.Click
        PanelOption.Visible = True
        Panelgraph.Visible = False




    End Sub

    Protected Sub Button9_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles ButtonDone.Click
        panelRealTimeMonitering.Visible = False

        PanelOption.Visible = True
        Panelgraph.Visible = True
        frame1.Attributes("src") = "1002.aspx?Value1=" + txtDate.Text



    End Sub
  




    Protected Sub Button8_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button8.Click
        Response.Redirect("Logging.aspx")
    End Sub

    Protected Sub Button2_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button2.Click
       



    End Sub

    Protected Sub Button9_Click1(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button9.Click

        Panelgraph.Visible = True
        PanelCalculation.Visible = True
        panelRealTimeMonitering.Visible = False


        frame1.Attributes("src") = "UserHome.aspx?Value=" + txtDate2.Text


    End Sub

    Protected Sub Button7_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button7.Click
        Panelgraph.Visible = False
        PanelCalculation.Visible = False
        panelRealTimeMonitering.Visible = True

        Iframe2.Attributes("src") = "online.aspx"
    End Sub

    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        PanelOption.Visible = False
        Panelgraph.Visible = False
        PanelCalculation.Visible = True
        panelRealTimeMonitering.Visible = False

    End Sub

    Protected Sub Button3_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button3.Click
        Iframe2.Attributes("src") = "report.aspx"

    End Sub
End Class
