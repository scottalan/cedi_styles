<?php
/**
 * @file
 * This template handles the layout of cj_balloon style.
 */
// class="oval-speech"
?>

<?php if (isset($settings['is_text'])): ?>
<div class="caption-balloon"><?php print render($settings['text']); ?></div>
<?php elseif (isset($settings['is_image'])): ?>
<!--  <div class="image-balloon">-->
    <?php print $content; ?>
    <div class="caption-balloon-image">
      <?php print $settings['text']['#items'][0]['value']; ?>
    </div>
<!--  </div>-->
<?php endif; ?>
