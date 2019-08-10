package works;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import works.Student;

public class Dreiver {
	public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		ArrayList<Student> listStu = new ArrayList<Student>();
		while (true) {
			System.out.println("--学生成绩管理系统--");
			System.out.println("1.键盘输入(并保存) ");
			System.out.println("2.输出到纯文本文件      ");
			System.out.println("3.查询统计                      ");
			System.out.println("4.从文本文件中载入数据");
			System.out.println("5.显示                             ");
			System.out.println("0.退出                      ");

			System.out.println("please choose (0-7):");
			int temp3 = scn.nextInt();

			switch (temp3) {
			case 0:
				Exit();
				break;
			case 1:
				listStu = inputStu();
				break;
			case 2:
				output(listStu);
				break;
			case 3:
				countStu(listStu);
				break;
			case 4:
				listStu = readStu();
				break;
			case 5:
				showStu(listStu);
				break;
			default:
				System.out.println("Input error!");
				;
				break;
			}
		}
	}

	// ********************键盘输入(并保存)*********************************
	private static ArrayList<Student> inputStu() throws Exception {
		// TODO Auto-generated method stub
		ArrayList<Student> listStu = new ArrayList<Student>();
		String[] strArray = { "1", "2", "3", "4" };
		int temp;
		do {
			Scanner scn = new Scanner(System.in);
			System.out.println("请输入学号 :");
			strArray[0] = scn.nextLine();
			System.out.println("请输入姓名：");
			if(listStu.size()>0){
				for(int i=0;i<listStu.size();i++){
					if(strArray[0].equals(listStu.get(i).getId())){
						System.out.println(listStu.get(i).getName());
						strArray[1] = listStu.get(i).getName();
					}
				}
				}
			else{
			strArray[1] = scn.nextLine();}
			
			System.out.println("请输入性别 :");
			if(listStu.size()>0){
				for(int i=0;i<listStu.size();i++){
					if(strArray[0].equals(listStu.get(i).getId())){
						System.out.println(listStu.get(i).getGender());
						strArray[3] = listStu.get(i).getGender();
					}
				}
				}
			else{
			strArray[2] = scn.nextLine();}
			
			System.out.println("请输入课程名 :");
			strArray[3] = scn.nextLine();
			if(listStu.size()>0){
			for(int i=0;i<listStu.size();i++){
				if(strArray[0].equals(listStu.get(i).getId())&&strArray[3].equals(listStu.get(i).getCourseName())){
					System.out.println("已存在该同学课程成绩，请重新输入课程名 :");
					strArray[3] = scn.nextLine();
				}
			}
			}
			System.out.println("请输入分数 :");
			float b = scn.nextFloat();
			Student stu = new Student(strArray[0], strArray[1], strArray[2], strArray[3], b);
			listStu.add(stu);
			System.out.print("是否继续添加（yes input 1/no input 0）?");
			temp = scn.nextInt();
		} while (temp == 1);
		File aFile = new File("C:\\Users\\a\\Desktop\\StudentNames.txt");
		FileWriter wr = new FileWriter(aFile);
		PrintWriter pw = new PrintWriter(wr);
		pw.println("学号\t姓名\t性别\t课程名称\t分数");
		pw.println("===\t===\t===\t====\t===");
		for (int i = 0; i < listStu.size(); i++) {
			String msg = listStu.get(i).getId() + "\t" + listStu.get(i).getName() + "\t" + listStu.get(i).getGender()
					+ "\t" + listStu.get(i).getCourseName() + "\t" + listStu.get(i).getScore();
			pw.println(msg);
		}
		pw.close();
		System.out.println("写入成功！");
		return listStu;
	}
	// *****************************************************************

	// *************************输出到纯文本文件*****************************************
	private static void output(ArrayList<Student> listStu) throws Exception {
		// TODO Auto-generated method stub
		ArrayList<Student> list1Stu = calAverage(listStu);
		File aFile = new File("C:\\Users\\a\\Desktop\\score.txt");
		FileWriter wr = new FileWriter(aFile);
		PrintWriter pw = new PrintWriter(wr);
		pw.println("学号\t姓名\t性别\t平均分\t总分");
		pw.println("===\t===\t===\t====");
		for (int i = 0; i < list1Stu.size(); i++) {
			String msg = list1Stu.get(i).getId() + "\t" + list1Stu.get(i).getName() + "\t" + list1Stu.get(i).getGender()
					+ "\t" + list1Stu.get(i).getArverage() + "\t" + list1Stu.get(i).getTotal();
			System.out.println(msg);
			pw.println(msg);
		}
		pw.close();
		System.out.println("写入成功！");
	}
	// *******************************************************************************

	// *******************查询统计***********************************
	private static void countStu(ArrayList<Student> list1Stu) {
		System.out.println("请输入要查询的学号：");
		Scanner scn = new Scanner(System.in);
		String id = scn.next();
		int i,count=0;
		for (i = 0; i < list1Stu.size(); i++) {
			if (id.equals(list1Stu.get(i).getId())) {
				//System.out.println("查寻成功！");
				count++;
				System.out.println("该学生姓名为"+list1Stu.get(i).getName()+" "+list1Stu.get(i).getCourseName()+" "+list1Stu.get(i).getScore());
			}
		}
		if (count==0) {
			System.out.println("不存在该学生！");
		}
	}
	// *************************************************************

	// ************************从文本文件中载入数据**************************
	private static ArrayList<Student> readStu() throws Exception {
		// TODO Auto-generated method stub
		ArrayList<Student> listStu = new ArrayList<Student>();
		File aFile = new File("C:\\Users\\a\\Desktop\\StudentNames.txt");
		FileReader fr = new FileReader(aFile);
		BufferedReader br = new BufferedReader(fr);
		br.readLine();
		br.readLine();
		String info = "";
		while ((info = br.readLine()) != null) {
			String a[] = info.split("\t");
			Student stu = new Student(a[0], a[1], a[2], a[3], Float.parseFloat(a[4]));
			listStu.add(stu);
		}
		br.close();
		System.out.println("载入成功！");
		return listStu;
	}
	// ****************************************************************

	// *****************显示***************************************
	private static void showStu(ArrayList<Student> listStu) {
		for (int i = 0; i < listStu.size(); i++) {
			String msg = listStu.get(i).getId() + "\t" + listStu.get(i).getName() + "\t" + listStu.get(i).getGender()
					+ "\t" + listStu.get(i).getCourseName() + "\t" + listStu.get(i).getScore();
			System.out.println(msg);
		}
	}
	// ************************************************************

	// ********Exit()**************************
	private static void Exit() {
		Scanner scn = new Scanner(System.in);
		System.out.println("确认退出系统？y/n");
		char temp2 = scn.next().charAt(0);
		if (temp2 == 'y' || temp2 == 'Y'){
			System.out.println("欢迎再次使用！！！");
			System.exit(0);}
	}
	// ***************************************

	// ***********************统计所有学生平均分，总分*************************************
	private static ArrayList<Student> calAverage(ArrayList<Student> listStu) {
		// TODO Auto-generated method stub
		for (int i = 0; i < listStu.size(); i++) {
			String id = listStu.get(i).getId();
			float total = 0;
			int count = 0;
			for (int j = 0; j < listStu.size(); j++) {
				String id1 = listStu.get(j).getId();
				if (id.equals(id1)) {
					total += listStu.get(j).getScore();
					count++;
				}
			}
			float avg = total / count;
			listStu.get(i).setTotal(total);
			listStu.get(i).setArverage(avg);
		}
		ArrayList<Student> listStu1=distinct(listStu);
		System.out.println("hello");
		return listStu1;
	}
   // *****************************************************************************
	private static ArrayList<Student> distinct(ArrayList<Student> listStu){
		ArrayList<Student> listStu1=new ArrayList<Student>();
		listStu1.add(listStu.get(0));
		int j;
		for(int i=1;i<listStu.size();i++){
			for(j=0;j<listStu1.size();j++){
				if(listStu.get(i).getId().equals(listStu1.get(j).getId())){
					break;
				}
			}
			if(j==listStu1.size()){
				listStu1.add(listStu.get(i));
			}
		}
		return listStu1;
	}
}













