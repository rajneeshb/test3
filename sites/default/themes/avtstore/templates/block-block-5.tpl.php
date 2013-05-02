<?php

/**
 * @file block.tpl.php
 *
 * Theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $block->content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: This is a numeric id connected to each module.
 * - $block->region: The block region embedding the current block.
 *
 * Helper variables:
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 */

  $profile = content_profile_load('profile', $user->uid);
  if (!empty($profile) ) {
    $name = array();

    if ( !empty($profile->field_first_name[0]['value']) ) {
      $name[] = $profile->field_first_name[0]['value'];
    }

    if ( !empty($profile->field_last_name[0]['value']) ) {
      $name[] = $profile->field_last_name[0]['value'];
    }

    $name = implode(' ', $name);
  }
  else {
    $name = $user->name;
  }

  $login_form = array();
  $weight = 0;

  $form['username'] = array(
      '#type' => 'textfield',
      '#name' => 'name',
      '#maxlength' => 60,
      '#id' => 'edit-name',
      '#default_value' => '',
      '#required' => TRUE,
      '#weight' => ++$weight,
      '#attributes' => array(
          'placeholder' => t('username'),
          'class' => 'customBackground',
          'tabindex' => 1,
        )
  );

  $form['password'] = array(
      '#type' => 'password',
      '#name' => 'pass',
      '#maxlength' => 60,
      '#id' => 'edit-pass',
      '#default_value' => '',
      '#required' => TRUE,
      '#weight' => ++$weight,
      '#attributes' => array(
          'placeholder' => t('password'),
          'class' => 'customBackground',
          'tabindex' => 2,
        )
  );

  $form['submit'] = array(
      '#type' => 'markup',
      '#weight' => ++$weight,
      '#value' => '<button type="submit" name="op" value="Log in" tabindex="3" class="fancy-button fancy-button-right fancy-button-small"><span class="fancy-button-start"></span><span class="fancy-button-text-wrap">Sign in</span><span class="fancy-button-end"></span></button>',
  );

  $form['form_id'] = array(
      '#type' => 'hidden',
      '#name' => 'form_id',
      '#id' => 'edit-user-login',
      '#value' => 'user_login',
  );

  ob_start();
?>
<?php if ( user_is_logged_in() ) : ?>
  <div class="top_loggedin">
    <?php echo l( t('Welcome back, @user-name', array('@user-name' => $name) ), 'user/' . $user->uid ); ?> |
    <?php echo l( t('Sign out'), 'logout'); ?>
  </div>
<?php else : ?>
  <form action="/user/login?<?php echo drupal_get_destination(); ?>" method="post" id="user-login">
    <?php echo drupal_render($form); ?>
  </form>
  <?php echo l( t('Forgot username/password?'), 'user/password', array( 'attributes' => array('class' => 'retrieve') ) ); ?>
<?php endif; ?>
<?php
  $block->content = ob_get_contents();
  ob_end_clean();

  include 'block.tpl.php';
?>