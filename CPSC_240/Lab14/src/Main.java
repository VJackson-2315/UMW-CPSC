import javax.swing.*;
import java.awt.event.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Lab 14");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel label = new JLabel("Enter a number in the field below to get its factorial");

        JTextField textField = new JTextField();

        JButton enter = new JButton("Calculate");
        enter.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                int input = Integer.parseInt(textField.getText());
                int x = 2;
                int ans = 1;
                while (x <= input) {
                    ans *= x;
                    x++;
                }
                JFrame answer = new JFrame("Factorial");
                JLabel factorial = new JLabel(Integer.toString(ans));
                answer.add(factorial);
                answer.pack();
                answer.show();
            }
        });

        frame.getContentPane().setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        frame.add(label);
        frame.add(textField);
        frame.add(enter);

        frame.pack();
        frame.setVisible(true);
    }
}
