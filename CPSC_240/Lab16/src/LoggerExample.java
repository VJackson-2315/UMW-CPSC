public class LoggerExample {
    public static void main(String args[]) {
        Logger log = Logger.instance();

        // turn off info and warning messages
        // log.setSevere(null);
        log.setInfo(null);
        log.setWarning(null);

        // test out some messages
        log.log(Logger.INFO, "this is a test");
        log.log(Logger.WARNING, "this might be a problem");
        log.log(Logger.ERROR, "error detected!");
    }
}