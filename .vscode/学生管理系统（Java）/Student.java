package works;

public class Student {
	private String id;
	private String name;
	private String gender;
	private String courseName;
	private float score;
	private float arverage;
	private float total;
	
	public Student() {
		super();
	}
	public Student(String id, String name, String gender, String courseName, float score) {
		super();
		this.id = id;
		this.name = name;
		this.gender = gender;
		this.courseName = courseName;
		this.score = score;
	}
	public String getCourseName() {
		return courseName;
	}
	public void setCourseName(String courseName) {
		this.courseName = courseName;
	}
	public float getScore() {
		return score;
	}
	public void setScore(float score) {
		this.score = score;
	}
	@Override
	public String toString() {
		return "Student [id=" + id + ", name=" + name + ", gender=" + gender + ", courseName=" + courseName + ", score="
				+ score + "]";
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public float getArverage() {
		return arverage;
	}
	public void setArverage(float arverage) {
		this.arverage = arverage;
	}
	public float getTotal() {
		return total;
	}
	public void setTotal(float total) {
		this.total = total;
	}
}
