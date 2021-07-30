# Druhé cvičenie

Poznámky z cvičenia

	package sk.tuke.oop.aliens;

    import sk.tuke.oop.aliens.actor.AbstractActor;
    import sk.tuke.oop.framework.Animation;

    public class Reactor extends AbstractActor {
        private final Animation hotAnimation;
        private int damage;
        private int temperature;
        private Animation normalAnimation;

        public Reactor() {
            damage = 9;
            temperature = 9;
            normalAnimation = new Animation("images/reactor_on.png", 80, 80, 100);
            // set actor's animation to just created Animation object
            setAnimation(normalAnimation);
            hotAnimation = new Animation("images/reactor_hot.png", 80, 80, 100);
        }


        public int getDamage() {
            return damage;
        }


        public int getTemperature() {
            return temperature;
        }

        public void increaseTemperature(int degrees) {
            this.temperature = temperature + degrees;

            if (temperature < 2000) {
                damage = 0;
            } else if (temperature >= 2000 && temperature <= 6000) {
                damage = (int) Math.floor((temperature - 2000.0) / 6000.0 * 100.0);
            }
        }

        private void updateAnimation(){
            if (temperature ){
                setAnimation(hotAnimation);
            }
        }


    }
