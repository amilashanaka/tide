
Partial Class Admin
    Inherits System.Web.UI.Page
    Dim optselect As Boolean


    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

        optselect = 0

        LabelDate.Text = System.DateTime.Now.ToString("dd MMMM yyyy")

        Dim welcomeText As String

        welcomeText = Request.QueryString("id")

        PanelOption.Visible = False
        Panelgraph.Visible = False
        PanelCalculation.Visible = False
        PanelCalculationEdit.Visible = False
        panelRealTimeMonitering.Visible = False


        LabelLogIn.Text = "WelCome  &nbsp " + welcomeText



    End Sub

 

    Protected Sub Button6_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnGraphGen.Click

        optselect = True
        PanelOption.Visible = True
        Panelgraph.Visible = False
        PanelCalculation.Visible = False
        PanelCalculationEdit.Visible = False
        panelRealTimeMonitering.Visible = False



    End Sub

    Protected Sub Button9_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles ButtonSmooth.Click



        panelRealTimeMonitering.Visible = False

        PanelOption.Visible = True
        Panelgraph.Visible = True
        frame1.Attributes("src") = "cal.aspx?Value1=" + txtDate.Text + "&Loc=" + dpLocGp.SelectedItem.Value.ToString()





    End Sub
  




    Protected Sub Button8_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button8.Click
        Response.Redirect("Logging.aspx")
    End Sub



    Protected Sub Button9_Click1(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnGetData.Click

        Panelgraph.Visible = True
        PanelCalculation.Visible = True
        PanelCalculationEdit.Visible = False
        panelRealTimeMonitering.Visible = False


        frame1.Attributes("src") = "UserHome.aspx?Value=" + txtDate2.Text + "&Loc=" + dpLoc.SelectedItem.Value.ToString()


    End Sub



    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        PanelOption.Visible = False
        Panelgraph.Visible = False
        PanelCalculation.Visible = True
        PanelCalculationEdit.Visible = False
        panelRealTimeMonitering.Visible = False

    End Sub
 

    Protected Sub Button2_Click1(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button2.Click

        Dim selectedLoc As String = String.Empty

        panelRealTimeMonitering.Visible = False

        PanelOption.Visible = True
        Panelgraph.Visible = True
        frame1.Attributes("src") = "1002.aspx?Value1=" + txtDate.Text + "&Loc=" + dpLocGp.SelectedItem.Value.ToString()

    End Sub

    Protected Sub Button3_Click(sender As Object, e As System.EventArgs) Handles Button3.Click
        PanelOption.Visible = False
        Panelgraph.Visible = False
        PanelCalculation.Visible = False
        PanelCalculationEdit.Visible = True
        panelRealTimeMonitering.Visible = False
    End Sub
    Protected Sub Button9_Click2(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnGetData1.Click

        Panelgraph.Visible = True
        PanelCalculation.Visible = False
        PanelCalculationEdit.Visible = True
        panelRealTimeMonitering.Visible = False


        frame1.Attributes("src") = "AdminEdit.aspx?Value=" + txtDate3.Text + "&Loc=" + dpLoc1.SelectedItem.Value.ToString()


    End Sub
End Class
