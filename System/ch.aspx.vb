Imports System.Data
Imports System.Data.SqlClient
Imports System.Configuration
Imports System.Web.UI.DataVisualization.Charting
Partial Class ch
    Inherits System.Web.UI.Page

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        BindData()
    End Sub

    Public Sub BindData()
        Using con As New SqlConnection("Data Source=tide;Initial Catalog=tide;Integrated Security=True")
            Dim CmdString As String = "select top 100 crunttime,hight from tideinfo"
            Dim sda As New SqlDataAdapter(CmdString, con)
            Dim ds As New DataSet()
            sda.Fill(ds)
            Chart1.DataSource = ds
            Chart1.Series("Series1").XValueMember = "crunttime"
            Chart1.Series("Series1").YValueMembers = "hight"
            Chart1.DataBind()
        End Using
    End Sub
End Class