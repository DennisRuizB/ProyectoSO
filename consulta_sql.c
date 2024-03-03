#include <stdio.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int err;
	char contrasena[25];
	int Id;
	char consulta[80];
	conn = mysql_init(NULL);
	if(conn==NULL){
		printf("Error al crear la conexion: %u %s\n",mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	conn=mysql_real_connect(conn, "localhost","root","mysql", NULL,0,NULL,0);
	if(conn==NULL){
		printf("Error al crear la conexion: %u %s\n",mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	err=mysql_query(conn,"use GrupoM6;");
	if(err!=0){
		printf("Error al crear la BD: %u %s\n",mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	printf("Dame la ID de un jugador para buscar su contraseña\n");
	scanf("%d",&Id);
	sprintf(consulta,"SELECT contrasena FROM Constrasenas WHERE Id = %d;", Id);
	err = mysql_query(conn,consulta);
	if(err!=0){
		printf("Error al consultar datos %u %s\n",mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	resultado = mysql_store_result(conn);
	row = mysql_fetch_row(resultado);
	if (row == NULL)
		printf("No se han obtenido datos de la consulta");
	else
		printf("Contraseña: %s\n",row[0]);
	
	mysql_close(conn);
	exit(0);
}
	
	
	
