package br.edu.exemplo.util;

import java.sql.*;
public class ConnectionFactory {

	public static Connection getConnection() throws Exception {

		try {

			// indica qual é o banco de dados que estou utilizando e seu driver
			Class.forName("com.mysql.jdbc.Driver");

			// estabelece a conexao e retorna uma conexao
			String login = "root";
			String senha = "root";
			String url = "jdbc:mysql://localhost:3306/academico";
			return DriverManager.getConnection(url,login,senha);

		} catch (Exception e) {
			throw new Exception(e.getMessage());
		}

	}

	/*public static void main(String args[]) {
		try {
			Connection con = ConnectionFactory.getConnection();
			System.out.println("FUNCIONOU!");
		} catch(Exception e) {
			System.out.println("sinto muito");
			e.printStackTrace();
		}
	}*/
	
	// fecha uma conexao de tres formas: conn, stmt, rs
	public static void closeConnection(Connection conn, Statement stmt, ResultSet rs) throws Exception {
		close(conn, stmt, rs);
	}
	public static void closeConnection(Connection conn, Statement stmt) throws Exception {
		close(conn, stmt, null);
	}
	public static void closeConnection(Connection conn) throws Exception {
		close(conn, null, null);
	}
	private static void close(Connection conn, Statement stmt, ResultSet rs) throws Exception {
		try {
			if (rs != null)
				rs.close();
			if (stmt != null)
				stmt.close();
			if (conn != null)
				conn.close();
		} catch (Exception e) {
			throw new Exception(e.getMessage());
		}
	}
}

