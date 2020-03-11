Imports System.Data.SqlClient
Imports System.Data
Imports System.IO
Imports System.Web.UI


Partial Class UserHome
    Inherits System.Web.UI.Page
    Public logginfo As String
    Public Loc As String
    Private strConnString As String = ConfigurationManager.ConnectionStrings("tide").ConnectionString
    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

        dataPanel.Visible = False
        logginfo = Request.QueryString("id")


        If (Page.IsPostBack) Then Return

        Loc = Request.QueryString("Loc").Trim()
        lblLocval.Text = Loc
        If (Loc = "1002") Then

            'lblLoc.Text = "Colombo"

        ElseIf (Loc = "1003") Then

            'lblLoc.Text = "Trincomalee"
        End If

        Dim text1 As String
        text1 = Request.QueryString("Value")

        Dim parts As String() = text1.Split(New Char() {"/"c})

        If parts(0).StartsWith("0") Then
            parts(0) = parts(0).Trim({" "c, "0"c})
        End If

        If parts(1).StartsWith("0") Then
            parts(1) = parts(1).Trim({" "c, "0"c})
        End If


        text1 = parts(0) + "/" + parts(1) + "/" + parts(2)


        Dim strSQL As String = String.Empty
        Resultview.DataSourceID = String.Empty
        Resultview.DataSource = String.Empty


        ' Define your select statement
        'strSQL = "select * from tideinfo where loc ='1002' and crunttime like' 1/21/2015 %' order by recid  "
        strSQL = "select [recid],[crunttime],[hight],[temp] from tideinfo where loc ='" + Loc + "' and crunttime like'" + text1 + "%' order by recid  "

        'strSQL = "select * from tideinfo where loc ='1002' and crunttime like'" + text1 + "%' order by recid  "
        'strSQL = "select hight from tideinfo where loc =1002 and tideinfo.crunttime like '" + text1.Trim() + "%'  order by recid"

        'strSQL = "select * from tideinfo where crunttime like'9/3/2014%'"
        ' Fire up SQLConnection with a DataReader

        Using confill As New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")



            confill.Open()
            Dim command As New SqlCommand(strSQL, confill)
            'Dim reader As SqlDataReader = command.ExecuteReader()
            Dim dt As New Data.DataTable

            'command.ExecuteReader()
            Dim dA As New SqlDataAdapter(command)

            dA.Fill(dt)


            'Resultview.AutoGenerateColumns = True
            'reader.Read()
            Resultview.DataSource = dt
            Resultview.DataBind()

            confill.Close()

            dataPanel.Visible = True


        End Using


    End Sub


    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        Response.ClearContent()
        Response.Buffer = True
        Response.AddHeader("content-disposition", String.Format("attachment; filename={0}", "tide" + Request.QueryString("Value") + ".xls"))
        Response.ContentType = "application/ms-excel"
        Dim sw As New StringWriter()
        Dim htw As New HtmlTextWriter(sw)
        Resultview.AllowPaging = False
        Resultview.HeaderRow.Style.Add("background-color", "#FFFFFF")
        For i As Integer = 0 To Resultview.HeaderRow.Cells.Count - 1
            Resultview.HeaderRow.Cells(i).Style.Add("background-color", "#df5015")
        Next
        Resultview.RenderControl(htw)
        Response.Write(sw.ToString())
        Response.[End]()
    End Sub
    Public Overrides Sub VerifyRenderingInServerForm(ByVal control As Control)
        ' DONOT DELETE this is importnt 

    End Sub
    
    Protected Sub Resultview_SelectedIndexChanged(sender As Object, e As EventArgs) Handles Resultview.SelectedIndexChanged

    End Sub
End Class
