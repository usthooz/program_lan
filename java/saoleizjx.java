import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;

public class saoleizjx extends JFrame implements ActionListener {
	
	private static final long serialVersionUID = 1L;
	private Container contentPane;
	private JButton b1;//开始按钮
	private JLabel a1;//标签，剩余雷的数量
	private JLabel a2;//标签，放置时间
	// private JButton[] bt;//布雷
	private int row=9;//行
	private int col=9;//列
	private int bon=10;//布雷的数量
	private int b;
    private JPanel S,s1,s2,s3;

    // 初始化
    JButton[] bt = new JButton[row * col];
	
	public saoleizjx(String title) {//构造方法
		super(title);
		contentPane=getContentPane();
		this.setBounds(400, 100, 400, 500);
		setSize(300,400);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		initGUI();//图形界面
	}
	
	public void initGUI() {
		
		b1=new JButton("开始");
		a1=new JLabel("3");
		a2=new JLabel("时间");
		s1=new JPanel();
		s1.add(b1);
		s1.add(a1);
		s1.add(a2);
		//面板s1，放置开始按钮和标签
		
		JMenuBar h=new JMenuBar();
		JMenu M1=new JMenu("游戏");
		JMenu M2=new JMenu("帮助");
		JMenu m1=new JMenu("初级");
		JMenu m2=new JMenu("中级");
		JMenu m3=new JMenu("高级");
		h.setSize(30, 30);
		h.add(M1);
		h.add(M2);
		M1.add(m1);
		M1.add(m2);
		M1.add(m3);
		s2=new JPanel();
		s2.add(h);
		//面板s2，放置菜单
		
		s3=new JPanel();
        s3.setLayout(new GridLayout(9,9,0,0));
		//网格布局
		for(int i=0;i<row*col;i++) {
			bt[i]=new JButton("");
			bt[i].setSize(30, 30);
			bt[i].setMargin(new Insets(0, 0, 0, 0));//间距
			s3.add(bt[i]);
		}
		//面板s3，布雷
		
		S=new JPanel();
		S.add(s1,BorderLayout.CENTER);
		S.add(s2,BorderLayout.NORTH);
		S.setLayout(new BorderLayout());
		//面板S，放置面板s1、s3
		
		contentPane.add(S,BorderLayout.NORTH);
		contentPane.add(s3,BorderLayout.CENTER);
	}
	
	public void go() {
		contentPane.setVisible(true);
	}
	
	public static void main(String []args) {
		new saoleizjx("扫雷自己写").go();
		
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub

	}

}
