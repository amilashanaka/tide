Imports System.Data.SqlClient
Partial Class datacap
    Inherits System.Web.UI.Page
    Public hight_dat As String
    Public temp_dat As String
    Public loc_data As String
    Public w_speed As String
    Public w_direc As String
    Public current_time As String
    Dim tempc As Double

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Dim temph As Integer
        hight_dat = "0"
        temp_dat = "0"
        loc_data = "0"
        hight_dat = Request.QueryString("Hight")
        temp_dat = Request.QueryString("Temp")
        loc_data = Request.QueryString("Loc")
        w_speed = Request.QueryString("Sp")
        w_direc = Request.QueryString("Wdir")
        temph = CInt(hight_dat) + 0
       hight_dat = temph.ToString()

        tempc = Double.Parse(temp_dat) - 1.06
        temp_dat = tempc.ToString()
        current_time = System.DateTime.Now.ToString("MM/dd/yyyy HH:MM")
        current_time = current_time.Trim()
        lbldatetime.Text = current_time
        lblHight.Text = hight_dat
        lbltemp.Text = temp_dat

        Dim strSQL As String = String.Empty
        Using con As New SqlConnection("Data Source=shanaka;Initial Catalog=tide;Integrated Security=True")
            Dim strSQLdata As String = String.Empty

            strSQLdata = "insert into dbo.tideinfo(crunttime,hight,temp,loc) values ('" + current_time + "','" + hight_dat + "','" + temp_dat + "','" + loc_data + "')"
            'strSQLdata = "insert into dbo.tideinfo(crunttime,hight,temp,loc) values ('2014-12-04 04:48:46.000','" + hight_dat + "','" + temp_dat + "','" + loc_data + "')"
            Dim command As New SqlCommand(strSQLdata, con)
            con.Open()


            Try
                If (temph > 20) Then
                    command.ExecuteNonQuery()
                End If


            Catch ex As Exception

                Response.Write(ex.ToString())

            End Try



            con.Close()



        End Using


        'Using conWind As New SqlConnection("Data Source=tide;Initial Catalog=wind;Integrated Security=True")

        '    Dim strWind As String = String.Empty

        '    strWind = "insert into dbo.info(time,speed,direction,loc) values ('" + current_time + "','" + w_speed + "','" + w_direc + "','" + loc_data + "')"

        '    Dim wcmd As New SqlCommand(strWind, conWind)
        '    conWind.Open()


        '    Try

        '        wcmd.ExecuteNonQuery()

        '    Catch ex As Exception

        '        Response.Write(ex.ToString())

        '    End Try



        '    conWind.Close()

        'End Using




    End Sub

    Protected Sub Page_PreLoad(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.PreLoad
        
    End Sub
End Class
