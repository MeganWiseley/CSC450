package concurrency.project;

public class ConcurrencyMain {

	public static void main(String[] args) {
		//Thread to count up
		Thread countUpThread = new Thread(new CountUpRunnable(), "Counting Up");
		//Thread to count down
		Thread countDownThread = new Thread(new CountDownRunnable(), "Counting Down");
		
		countUpThread.start();
		
		try {
			//Wait until count up thread is finished before starting count down thread
			countUpThread.join();
		}
		
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		countDownThread.start();
	}

}
