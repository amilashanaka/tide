Imports System.IO
Imports System.Data.SqlClient
Imports System.Data

Partial Class AdminEdit
    Inherits System.Web.UI.Page
    Public logginfo As String
    Public Loc As String
    Private strConnString As String = ConfigurationManager.ConnectionStrings("tide1").ConnectionString
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
        lblDate.Text = text1

        'Dim strSQL As String = String.Empty
        'Resultview.DataSourceID = String.Empty
        'Resultview.DataSource = String.Empty


        '' Define your select statement
        ''strSQL = "select * from tideinfo where loc ='1002' and crunttime like' 1/21/2015 %' order by recid  "
        'strSQL = "select [recid],[crunttime],[hight],[temp] from tideinfo where loc ='" + Loc + "' and crunttime like'" + text1 + "%' order by recid  "

        ''strSQL = "select * from tideinfo where loc ='1002' and crunttime like'" + text1 + "%' order by recid  "
        ''strSQL = "select hight from tideinfo where loc =1002 and tideinfo.crunttime like '" + text1.Trim() + "%'  order by recid"

        ''strSQL = "select * from tideinfo where crunttime like'9/3/2014%'"
        '' Fire up SQLConnection with a DataReader

        'Using confill As New SqlConnection("Data Source=tide;Initial Catalog=tide;Integrated Security=True")



        '    confill.Open()
        '    Dim command As New SqlCommand(strSQL, confill)
        '    'Dim reader As SqlDataReader = command.ExecuteReader()
        '    Dim dt As New Data.DataTable

        '    'command.ExecuteReader()
        '    Dim dA As New SqlDataAdapter(command)

        '    dA.Fill(dt)


        '    'Resultview.AutoGenerateColumns = True
        '    'reader.Read()
        '    Resultview.DataSource = dt
        '    Resultview.DataBind()

        '    confill.Close()
        If Not Me.IsPostBack Then
            Me.BindGrid()
        End If
        dataPanel.Visible = True


        'End Using


    End Sub



   Private Sub BindGrid()
        Dim constr As String = ConfigurationManager.ConnectionStrings("tide1").ConnectionString
        Using con As New SqlConnection(constr)
            Using cmd As New SqlCommand("SELECT recid, crunttime, hight ,temp FROM tideinfo where loc ='" + lblLocval.Text + "' and crunttime like'" + lblDate.Text + "%' order by recid")
                Using sda As New SqlDataAdapter()
                    cmd.Connection = con
                    sda.SelectCommand = cmd
                    Using dt As New DataTable()
                        sda.Fill(dt)
                        GridView1.DataSource = dt
                        GridView1.DataBind()
                    End Using
                End Using
            End Using
        End Using
    End Sub

    Protected Sub OnRowEditing(sender As Object, e As GridViewEditEventArgs)
        GridView1.EditIndex = e.NewEditIndex
        Me.BindGrid()
    End Sub

    Protected Sub OnRowCancelingEdit(sender As Object, e As EventArgs)
        GridView1.EditIndex = -1
        Me.BindGrid()
    End Sub

    Protected Sub OnRowUpdating(sender As Object, e As GridViewUpdateEventArgs)
        Dim row As GridViewRow = GridView1.Rows(e.RowIndex)
        Dim recid As Integer = Convert.ToInt32(GridView1.DataKeys(e.RowIndex).Values(0))
        Dim crunttime As String = TryCast(row.Cells(2).Controls(0), TextBox).Text
        Dim hight As String = TryCast(row.Cells(3).Controls(0), TextBox).Text
        Dim temp As String = TryCast(row.Cells(4).Controls(0), TextBox).Text
        Dim constr As String = ConfigurationManager.ConnectionStrings("tide1").ConnectionString
        Using con As New SqlConnection(constr)
            Using cmd As New SqlCommand("UPDATE tideinfo SET crunttime = @crunttime, hight = @hight, temp = @temp WHERE recid = @recid")
                cmd.Parameters.AddWithValue("@recid", recid)
                cmd.Parameters.AddWithValue("@crunttime", crunttime)
                cmd.Parameters.AddWithValue("@hight", hight)
                cmd.Parameters.AddWithValue("@temp", temp)
                cmd.Connection = con
                con.Open()
                cmd.ExecuteNonQuery()
                con.Close()
            End Using
        End Using
        GridView1.EditIndex = -1
        Me.BindGrid()
    End Sub

    Protected Sub OnRowDataBound(sender As Object, e As GridViewRowEventArgs)
        If e.Row.RowType = DataControlRowType.DataRow AndAlso e.Row.RowIndex <> GridView1.EditIndex Then
            TryCast(e.Row.Cells(0).Controls(2), LinkButton).Attributes("onclick") = "return confirm('Do you want to delete this row?');"
        End If
    End Sub

    Protected Sub OnRowDeleting(sender As Object, e As GridViewDeleteEventArgs)
        Dim recid As Integer = Convert.ToInt32(GridView1.DataKeys(e.RowIndex).Values(0))
        Dim constr As String = ConfigurationManager.ConnectionStrings("tide").ConnectionString
        Using con As New SqlConnection(constr)
            Using cmd As New SqlCommand("DELETE FROM tideinfo WHERE recid = @recid")
                cmd.Parameters.AddWithValue("@recid", recid)
                cmd.Connection = con
                con.Open()
                cmd.ExecuteNonQuery()
                con.Close()
            End Using
        End Using
        Me.BindGrid()
    End Sub

    Protected Sub btnAdd_Click(sender As Object, e As System.EventArgs) Handles btnAdd.Click
        Using myconnection As SqlConnection = New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")
            myconnection.Open()

            Using mycommand As SqlCommand = myconnection.CreateCommand
                ' Setup the SQL command with parameters.  Parameters protect from SQL injection exploits (and make your SQL easier to read/manage).
                mycommand.CommandText = "insert into tideinfo([crunttime],[hight],[temp],[loc]) values (@crunttime, @hight, @temp, @loc)"
                mycommand.Parameters.AddWithValue("@crunttime", txtcrunttime.Text)
                mycommand.Parameters.AddWithValue("@hight", txthight.Text)
                mycommand.Parameters.AddWithValue("@temp", txttemp.Text)
                mycommand.Parameters.AddWithValue("@loc", lblLocval.Text)

                Dim rowsAffected As Integer = mycommand.ExecuteNonQuery()
                ' This would be one always in this case unless the statement failed
                'MessageBox.Show("Rows inserted: " & rowsAffected)

            End Using

            myconnection.Close()
        End Using
    End Sub
End Class

