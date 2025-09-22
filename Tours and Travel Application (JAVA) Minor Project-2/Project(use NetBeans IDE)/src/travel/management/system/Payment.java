package travel.management.system;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class Payment extends JFrame{
    public Payment(){
        setLayout(null);
        setBounds(950, 90, 450, 650);
        JLabel label=new JLabel("Pay using Paytm");
        label.setFont(new Font("Raleway", Font.BOLD, 40));
        label.setBounds(50, 20, 350, 45);
        add(label);
        ImageIcon i7 = new ImageIcon(ClassLoader.getSystemResource("travel/management/system/icons/paytm.jpg"));
        Image i8 = i7.getImage().getScaledInstance(400, 400, Image.SCALE_DEFAULT);
        ImageIcon i9 = new ImageIcon(i8);
        JLabel l4 = new JLabel(i9);
        l4.setBounds(20, 100, 400, 400);
        add(l4);
        JButton back=new JButton("Back");
        back.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
            }
        });
        back.setBounds(180, 510, 80, 40);
        add(back);
        getContentPane().setBackground(Color.WHITE);
        setVisible(true);
    }
    public static void main(String[] args){
        new Payment().setVisible(true);
    }
}