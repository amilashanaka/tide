Imports System.Data.SqlClient
Partial Class cal
    Inherits System.Web.UI.Page
    Dim count As Integer
    Dim dataBank As New List(Of String)()


    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        If (Page.IsPostBack) Then Return
        Dim text1 As String
        Dim Loc As String
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
        strSQL = "select hight from tideinfo  where   loc ='" + Loc + "' and tideinfo.crunttime like '" + text1 + "%'  order by recid asc"

        ' strSQL = "select hight from tideinfo where  tideinfo.crunttime like '2/22/2015%'  order by recid asc"
        ' Fire up SQLConnection with a DataReader


        Using connection As New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")
            txtDataBank.Text = " "

            Dim command As New SqlCommand(strSQL, connection)
            connection.Open()
            Dim reader As SqlDataReader = command.ExecuteReader()
            Try
                Dim isFirst = True
                Dim i As Integer
                Dim r As Integer
                Dim val1 As String
                Dim val2 As String
                Dim val3 As String
                Dim result As Double

                i = 0

                While reader.Read()

                    ' Do some magic with reader.GetValue()
                    If isFirst Then
                        'txtDataBank.Text = reader.Item(0).ToString().Trim()
                        'dataBank.Add(reader.Item(0).ToString().Trim())
                        val1 = reader.Item(0).ToString().Trim()
                        txtDataBank.Text = val1

                        isFirst = False

                    Else

                        val2 = reader.Item(0).ToString().Trim()

                        result = 0.05 * Double.Parse(val2) + 0.95 * Double.Parse(val1)
                        r = Math.Round(result)
                        'val1 = Double.Parse(reader.Item(0).ToString().Trim())
                        'val2 = Double.Parse(reader.Item(0).ToString().Trim())
                        'result = 0.05 * val1 + 0.95 * val2
                        'txtDataBank.Text = txtDataBank.Text.ToString().Trim() + "," + dataBank(1)
                        txtDataBank.Text = txtDataBank.Text.ToString().Trim() + "," + r.ToString()

                        val1 = result.ToString()


                    End If

                    i = i + 1
                End While
            Catch ex As Exception

                reader.Close()
                connection.Close()


            End Try
            reader.Close()
            connection.Close()
        End Using
    End Sub
End Class
