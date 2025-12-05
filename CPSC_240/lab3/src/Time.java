public class Time {
    private int hour;
    private int minute;
    private int second;

    public Time() {
        hour = 00;
        minute = 00;
        second = 00;
    }

    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public void increment (int increase) {
        while (increase > 0) {
            second += 1;
            increase -= 1;
        }
        while (second >= 60) {
            minute += 1;
            second -= 60;
        }
        while (minute >= 60) {
            hour += 1;
            minute -= 60;
        }
    }

    public String convert (int i) {
        if (i < 10) {
            return "0" + i;
        } else {
            return "" + i;
        }
    }

    public void print (boolean military) {
        String h = convert(hour);
        String m = convert(minute);
        String s = convert(second);

        if (military) {
            System.out.printf("%s:%s:%s %n", h, m, s);
        } else {
            String ampm = "";

            if (hour > 12) {
                hour -= 12;
                h = convert(hour);
                ampm = "PM";
            } else if (hour == 0) {
                hour = 12;
                h = convert(hour);
                ampm = "AM";
            } else {
                ampm = "AM";
            }

            System.out.printf("%s:%s:%s %s %n", h, m, s, ampm);
        }
    }
}
