Imports System.Data.SqlClient
Partial Class _1002
    Inherits System.Web.UI.Page

    Dim count As Integer
    Dim Loc As String
    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load



  If (Page.IsPostBack) Then Return

        Dim text1 As String

        text1 = Request.QueryString("Value1")
        Loc = Request.QueryString("Loc")
        Dim parts As String() = text1.Split(New Char() {"/"c})

        If parts(0).StartsWith("0") Then
            parts(0) = parts(0).Trim({" "c, "0"c})
        End If

        If parts(1).StartsWith("0") Then
            parts(1) = parts(1).Trim({" "c, "0"c})
        End If

       

        text1 = parts(0) + "/" + parts(1) + "/" + parts(2)

        'Dim aString As String
        'aString = text1.Chars(2)
        'Dim ddd As String = "0"
        'If aString.Contains(ddd) Then

        '    Dim firstString As String = text1.Substring(0, 2)
        '    Dim secondString As String = text1.Substring(3, 6)
        '    text1 = String.Concat(firstString, secondString)

        'End If



            Dim strSQL As String = String.Empty
            Dim sty As String

            sty = System.DateTime.Now.ToString()
            sty = "'" + sty + "%'"
            ' Define your select statement
            'strSQL = "select hight from tideinfo where loc =1002 and tideinfo.crunttime between '10/08/2014 00:00:00' and '10/09/2014 00:00:00' order by recid desc"
        strSQL = "select hight,crunttime from tideinfo  where   loc ='" + Loc + "' and tideinfo.crunttime like '" + text1 + "%'  order by recid asc"
        'strSQL = "select hight from tideinfo where  tideinfo.crunttime like '7/7/2015%'  order by recid asc"
            ' Fire up SQLConnection with a DataReader


        Using connection As New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")
            txtdatabank.Text = " "

            Dim command As New SqlCommand(strSQL, connection)
            connection.Open()
            Dim reader As SqlDataReader = command.ExecuteReader()
            Dim xstr As String
            Dim ts As Date
            Try
                Dim isFirst = True

                While reader.Read()

                    ' Do some magic with reader.GetValue()
                    If isFirst Then
                        txtdatabank.Text = reader.Item(0).ToString().Trim()
                        xstr = reader.Item(1).ToString().Trim()

                        ts = Date.Parse(xstr)
                        txtX.Text = ts.Hour.ToString()
                        isFirst = False

                    Else

                        txtdatabank.Text = txtdatabank.Text.ToString().Trim() + "," + reader.Item(0).ToString().Trim()
                        xstr = reader.Item(1).ToString().Trim()
                        ts = Date.Parse(xstr)
                        txtX.Text = txtX.Text.ToString().Trim() + "," + ts.Hour.ToString()
                    End If


                End While
            Catch ex As Exception

                reader.Close()
                connection.Close()


            End Try
            reader.Close()
            connection.Close()
        End Using
    End Sub

    Protected Sub Timer1_Tick(ByVal sender As Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Dim strtide As String = String.Empty

        strtide = "select TOP 1 (hight) from tideinfo where loc ='" + Loc + "' order by recid desc "
        count = 0

        Using contide As New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")

            Dim cmdtide As New SqlCommand(strtide, contide)
            contide.Open()
            Dim readertide As SqlDataReader = cmdtide.ExecuteReader()

            While readertide.Read()



            End While



            contide.Close()

        End Using
    End Sub
End Class
