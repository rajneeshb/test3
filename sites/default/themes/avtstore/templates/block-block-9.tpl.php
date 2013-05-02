<?php ob_start(); ?>
<?php if ( user_is_anonymous() ) : ?>
  <form action="<?php print "/{$base_path}user/login/?".drupal_get_destination();?>" method="post" id="user-login">
    <div class="login-inner">
      <h3 class="title">Already have an account?</h3>
      <label class="signin">sign in</label>
      <input type="text" maxlength="60" name="name" id="edit-name" value="" tabindex="1" class=" form-text customBackground textOff required" onfocus="this.className='textOn';" />
      <input type="password" name="pass" id="edit-pass" value="" tabindex="2" class="form-text customBackground passOff required" onfocus="this.className='passOn';" />
      <input type="hidden" name="form_id" id="edit-user-login" value="user_login" />
      <input type="submit" align="middle" name="op" class="form-submit" id="edit-submit" tabindex="3" value="Log in" src="/submit.png" alt="Submit" />
    </div>
    <a class="retrieve" href="/user/password">Forgot username/password?</a>
  </form>
<?php endif; ?>
<?php
  $block->content = ob_get_contents();
  ob_end_clean();

  include 'block.tpl.php';

