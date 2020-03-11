Imports System.Data.SqlClient
Partial Class online
    Inherits System.Web.UI.Page
    Public Loc As String
    Dim count As Integer
    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

        If (Page.IsPostBack) Then Return

        Loc = Request.QueryString("Loc").Trim()
        lblLocval.Text = Loc
        If (Loc = "1002") Then

            lblLoc.Text = "Colombo"

        ElseIf (Loc = "1003") Then

            lblLoc.Text = "Trincomalee"

        ElseIf (Loc = "1004") Then

            lblLoc.Text = "Galle"

        ElseIf (Loc = "1005") Then

            lblLoc.Text = "KKS"

        ElseIf (Loc = "1006") Then

            lblLoc.Text = "Delft Jetty"
        End If



        lblLocval.Visible = False
    End Sub



    Protected Sub TimerHight_Tick(ByVal sender As Object, ByVal e As System.EventArgs) Handles TimerHight.Tick
        Dim strtide As String = String.Empty


        strtide = "select TOP 1 (hight) from tideinfo where loc ='" + lblLocval.Text + "' order by recid desc "
        count = 0

        Using contide As New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")

            Dim cmdtide As New SqlCommand(strtide, contide)
            contide.Open()
            Dim readertide As SqlDataReader = cmdtide.ExecuteReader()

            While readertide.Read()

                Try
                    txtHight.Text = readertide.Item(0).ToString() + " cm"


                Catch ex As Exception
                    txtHight.Text = "Cant Read"
                    contide.Close()

                End Try

            End While



            contide.Close()

        End Using
    End Sub
End Class
