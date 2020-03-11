Imports System.Data.SqlClient

Partial Class Logging
    Inherits System.Web.UI.Page

    Public loginfo As String
    Public cont As Integer
    Public hight As String

    Protected Sub form1_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles frmLogging.Load


        lblDate.Text = System.DateTime.Now.ToString("dd MMMM yyyy")
        LogPanel.Visible = False
        lblLog.Text = " "

        hight = "0"


        hight = Request.QueryString("Hight")

       
    End Sub
    Protected Sub btnLogging_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnLogging.Click


        LogPanel.Visible = True

    End Sub

    Protected Sub btnlogsub_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnlogsub.Click


        Dim strSQL As String = String.Empty

        ' Define your select statement
        strSQL = "select usrid,pass,name from usr where usrid='" + txtusrName.Text.Trim() + "'"
        ' Fire up SQLConnection with a DataReader

        Using connection As New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")


            Dim command As New SqlCommand(strSQL, connection)
            connection.Open()
            Dim reader As SqlDataReader = command.ExecuteReader()



            While reader.Read()
                Try
                    ' Do some magic with reader.GetValue()


                    If (txtusrName.Text.Trim() = reader.Item(0).ToString().Trim()) Then


                        If (txtpass.Text.Trim() = reader.Item(1).ToString().Trim()) Then
                            loginfo = reader.Item(2).ToString().Trim()

                            btnLogging.Text = "Log Off"
                            Response.Redirect("Admin.aspx?id=" & loginfo)

                        Else
                            lblLog.Text = "Incorrect Password" + reader.Item(1).ToString() + " " + txtpass.Text
                            btnLogging.Text = "Log Off"
                        End If





                    Else
                        lblLog.Text = "User not found "


                    End If



                Catch ex As Exception

                    reader.Close()
                    connection.Close()
                    lblLog.Text = "Exepetion"

                End Try
            End While

            reader.Close()
            connection.Close()
        End Using

    End Sub


   

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
   





    End Sub

   
End Class
